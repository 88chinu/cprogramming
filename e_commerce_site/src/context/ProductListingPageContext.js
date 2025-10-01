import React, { createContext, useContext, useReducer } from "react";

// 1️⃣ Create context
const ProductDataContext = createContext();

// 2️⃣ Initial state
const initialState = {
  products: [],
  isLoading: true,
};

// 3️⃣ Reducer (you can expand this with more actions later)
function productDataReducer(state, action) {
  switch (action.type) {
    case "SET_PRODUCTS":
      return { ...state, products: action.payload, isLoading: false };
    case "LOADING":
      return { ...state, isLoading: true };
    default:
      return state;
  }
}

// 4️⃣ Provider
export function ProductDataProvider({ children }) {
  const [state, dispatch] = useReducer(productDataReducer, initialState);

  return (
    <ProductDataContext.Provider value={{ ...state, dispatch }}>
      {children}
    </ProductDataContext.Provider>
  );
}

export function useProductDataContext() {
  return useContext(ProductDataContext);
}
