import React from "react";
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";

// Context Providers
// import { CartProvider } from "./context/CartContext";
// import { WishlistProvider } from "./context/WishlistContext";
// import { FilterProvider } from "./context/FilterContext";
// import { ProductProvider } from "./context/ProductContext";
import { ProductDataProvider } from "./context/ProductListingPageContext";

// Pages
import Homepage from "./pages/HomePage/Homepage";
import ProductListingPage from "./context/ProductListingPageContext";
// import SingleProductPage from "./pages/SingleProductPage/SingleProductPage";
// import CartPage from "./pages/CartPage/CartPage";
// import WishlistPage from "./pages/WishlistPage/WishlistPage";
// import CheckoutPage from "./pages/CheckoutPage/CheckoutPage";
// import OrderSuccessPage from "./pages/OrderSuccessPage/OrderSuccessPage";
// import ProfilePage from "./pages/ProfilePage/ProfilePage";
// import LoginPage from "./pages/Auth/LoginPage";
// import SignupPage from "./pages/Auth/SignupPage";

function App() {
  return (
    <Router>
      {/* <CartProvider> */}
        {/* <WishlistProvider> */}
          {/* <FilterProvider> */}
            {/* <ProductProvider> */}
              {/* <ProductDataProvider> */}
                <Routes>
                  <Route path="/" element={<Homepage />} />
                  <Route path="/ProductListingPage" element={<ProductListingPage />} />
                  <Route path="/Productdetails/:id" element={<SingleProductPage />} />
                  {/* <Route path="/CartPage" element={<CartPage />} /> */}
                  {/* <Route path="/WishlistPage" element={<WishlistPage />} /> */}
                  {/* <Route path="/CheckoutPage" element={<CheckoutPage />} />
                  <Route path="/OrderSuccessPage" element={<OrderSuccessPage />} /> */}
                  {/* <Route path="/AccountPage" element={<ProfilePage />} /> */}
                  {/* <Route path="/LoginPage" element={<LoginPage />} /> */}
                  {/* <Route path="/SignupPage" element={<SignupPage />} /> */}
                </Routes>
              {/* </ProductDataProvider> */}
            {/* </ProductProvider> */}
          {/* </FilterProvider> */}
        {/* </WishlistProvider> */}
      {/* </CartProvider> */}
    </Router>
  );
}

export default App;
