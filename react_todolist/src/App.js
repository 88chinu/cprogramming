import React from "react";
import "./App.css";

function Todo({ todo, index, completeTodo, removeTodo }) {
  return (
    <div
      className={`todo ${todo.isCompleted ? "completed" : ""}`}
    >
      <span>{todo.text}</span>
      <div>
        <button className="btn complete" onClick={() => completeTodo(index)}>
          {todo.isCompleted ? "Undo" : "Complete"}
        </button>
        <button className="btn delete" onClick={() => removeTodo(index)}>x</button>
      </div>
    </div>
  );
}

function TodoForm({ addTodo }) {
  const [value, setValue] = React.useState("");

  const handleSubmit = e => {
    e.preventDefault();
    if (!value.trim()) return;
    addTodo(value);
    setValue("");
  };

  return (
    <form onSubmit={handleSubmit} className="todo-form">
      <input
        type="text"
        className="input"
        placeholder="Add a new task..."
        value={value}
        onChange={e => setValue(e.target.value)}
      />
      <button className="btn add">Add</button>
    </form>
  );
}

function App() {
  const [todos, setTodos] = React.useState([
    { text: "Learn about React", isCompleted: false },
    { text: "Meet friend for lunch", isCompleted: false },
    { text: "Build really cool todo app", isCompleted: false }
  ]);

  const addTodo = text => {
    const newTodos = [...todos, { text, isCompleted: false }];
    setTodos(newTodos);
  };

  const completeTodo = index => {
    const newTodos = [...todos];
    newTodos[index].isCompleted = !newTodos[index].isCompleted; // toggle
    setTodos(newTodos);
  };

  const removeTodo = index => {
    const newTodos = [...todos];
    newTodos.splice(index, 1);
    setTodos(newTodos);
  };

  const clearCompleted = () => {
    const newTodos = todos.filter(todo => !todo.isCompleted);
    setTodos(newTodos);
  };

  return (
    <div className="app">
      <h1 className="title">Todo App</h1>
      <TodoForm addTodo={addTodo} />

      <div className="todo-list">
        {todos.map((todo, index) => (
          <Todo
            key={index}
            index={index}
            todo={todo}
            completeTodo={completeTodo}
            removeTodo={removeTodo}
          />
        ))}
      </div>

      <div className="footer">
        <p>{todos.filter(todo => !todo.isCompleted).length} tasks left</p>
        <button className="btn clear" onClick={clearCompleted}>Clear Completed</button>
      </div>
    </div>
  );
}

export default App;
