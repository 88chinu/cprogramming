import React, { useState } from "react"
import logo from "./logo.svg"
import "./App.css"

function Todo({ todo }) {
  return (
    <div className="todo">
      {todo.text}
    </div>
  )
}

function App() {
  const [todos, setTodos] = useState([
    { text: "Learn React" },
    { text: "Go to friend's house" },
    { text: "Build ToDo List" },
  ])

  return (
    <div className="app">
      <div className="todo-list">
        {todos.map((todo, index) => (
          <Todo key={index} index={index} todo={todo} />
        ))}
      </div>
    </div>
  )
}

export default App
