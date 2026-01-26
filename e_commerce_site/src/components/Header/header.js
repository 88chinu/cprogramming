import React, { useState } from "react";
import { Link } from "react-router-dom";

import {
  useCartContext,
  useFilterContext,
  useWishlistContext,
} from "../../context/AllContextIndex";

function Header() {
  const [isMenuOpen, setIsMenuOpen] = useState(false);

  const { cart } = useCartContext();
  const { wish } = useWishlistContext();
  const { dispatch } = useFilterContext();

  const token = window.localStorage.getItem("token");

  return (
    <div>
      <div className="flex flex-row items-center justify-between w-full p-2 sm:px-4 shadow-xl bg-gray-700 fixed top-0">
        {/* Logo */}
        <Link to="/">
          <div className="ml-8 text-lg text-white hidden md:flex">Car-kit</div>
        </Link>

        {/* Search bar */}
        <span className="w-full md:w-1/3 h-10 cursor-pointer border border-gray-300 text-sm rounded-full flex">
          <input
            type="search"
            onChange={(e) =>
              dispatch({ type: "SEARCHBAR", payload: e.target.value })
            }
            placeholder="Search"
            className="flex-grow px-4 rounded-l-full rounded-r-full text-sm focus:outline-none"
          />
        </span>

        {/* Icons */}
        <div className="flex text-white text-2xl">
          <div className="flex w-48 justify-between">
            {/* Store */}
            <Link to="/ProductListingPage">
              <span className="material-icons">store</span>
            </Link>

            {/* Wishlist */}
            <div className="relative">
              <Link to="/WishlistPage">
                <span className="material-icons">favorite</span>
              </Link>
              <span className="w-4 h-4 rounded-full text-center absolute -top-2 -right-2 text-xs bg-red-500">
                {wish.length}
              </span>
            </div>

            {/* Cart */}
            <div className="relative">
              <Link to="/CartPage">
                <span className="material-icons">shopping_cart</span>
              </Link>
              <span className="w-4 h-4 rounded-full text-center absolute -top-2 -right-2 text-xs bg-red-500">
                {cart.length}
              </span>
            </div>

            {/* Auth */}
            {!token ? (
              <Link to="/LoginPage">
                <span className="material-icons">login</span>
              </Link>
            ) : (
              <Link to="/AccountPage">
                <span className="material-icons">account_circle</span>
              </Link>
            )}
          </div>
        </div>
      </div>
    </div>
  );
}

export default Header;
