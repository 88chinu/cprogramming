import React, { useState, useEffect } from "react";
import { Link, useNavigate } from "react-router-dom";

// import "../../Utils/CustomCSSUtils.css";
// import { useLoginContext } from "../../Context/AllContextIndex";
// import { loginHandler } from "../../Services/AuthServices";

function LoginInputs() {
  const { dispatch, email, password, name } = useLoginContext();
  const navigate = useNavigate();

  const [error, setError] = useState("");
  const [isDisabled, setIsDisabled] = useState(true);

  // handle login form submit
  function submitLoginData(e) {
    e.preventDefault();
    loginHandler(email, password, dispatch);
    navigate("/ProductListingPage");
  }

  // validate form inputs
  useEffect(() => {
    if (email.length > 0 && password.length > 0) {
      setError("");
      setIsDisabled(false);
    } else {
      setError("All fields must be filled.");
      setIsDisabled(true);
    }
  }, [email, password]);

  // guest login
  function setGuestLoginData(e) {
    e.preventDefault();
    const email = "6prankur@gmail.com";
    const password = "12345678";
    const name = `Guest`;

    dispatch({ type: "EMAIL", payload: email });
    dispatch({ type: "PASSWORD", payload: password });
    dispatch({ type: "NAME", payload: name });
  }

  return (
    <div>
      <section className="text-gray-400 bg-gray-900 body-font">
        <div className="container px-5 py-24 mx-auto flex flex-wrap items-center">
          <div className="lg:w-3/5 md:w-1/2 md:pr-16 lg:pr-0 pr-0">
            <h1 className="title-font font-medium text-3xl text-white">
              Slow-carb next level shoindxgoitch ethical authentic, poko
              scenester
            </h1>
            <p className="leading-relaxed mt-4">
              Poke slow-carb mixtape knausgaard, typewriter street art gentrify
              hammock starladder roathse. Craies vegan tousled etsy austin.
            </p>
          </div>

          <div className="lg:w-2/6 md:w-1/2 bg-gray-800 bg-opacity-50 rounded-lg p-8 flex flex-col md:ml-auto w-full mt-10 md:mt-0">
            <h2 className="text-white text-lg font-medium title-font mb-5">
              Log In
            </h2>

            <div>
              <form onSubmit={submitLoginData}>
                <div className="relative mb-4">
                  <label
                    htmlFor="email"
                    className="leading-7 text-sm text-gray-400"
                  >
                    Email
                  </label>
                  <input
                    id="email"
                    type="email"
                    value={email}
                    name="email"
                    onChange={(e) =>
                      dispatch({ type: "EMAIL", payload: e.target.value })
                    }
                    className="w-full bg-gray-600 bg-opacity-20 focus:bg-transparent focus:ring-2 focus:ring-red-900 rounded border border-gray-600 focus:border-red-500 text-base outline-none text-gray-100 py-1 px-3 leading-8 transition-colors duration-200 ease-in-out"
                    placeholder="Enter your email"
                  />
                </div>

                <div className="relative mb-4">
                  <label
                    htmlFor="password"
                    className="leading-7 text-sm text-gray-400"
                  >
                    Password
                  </label>
                  <input
                    id="password"
                    type="password"
                    name="password"
                    value={password}
                    placeholder="Enter your password"
                    onChange={(e) =>
                      dispatch({ type: "PASSWORD", payload: e.target.value })
                    }
                    className="w-full bg-gray-600 bg-opacity-20 focus:bg-transparent focus:ring-2 focus:ring-red-900 rounded border border-gray-600 focus:border-red-500 text-base outline-none text-gray-100 py-1 px-3 leading-8 transition-colors duration-200 ease-in-out"
                  />
                </div>

                <div className="flex flex-col">
                  <input
                    type="submit"
                    disabled={isDisabled}
                    className={`text-white border-0 py-2 px-8 rounded text-lg cursor-pointer ${
                      isDisabled
                        ? "bg-gray-500 cursor-not-allowed"
                        : "bg-red-500 hover:bg-red-600"
                    }`}
                    value="Login"
                  />

                  <button
                    className="text-white bg-blue-500 border-0 py-2 px-8 focus:outline-none hover:bg-blue-600 rounded text-lg mt-2"
                    onClick={setGuestLoginData}
                  >
                    Guest Login
                  </button>
                </div>
              </form>
            </div>

            {error && <p className="text-red-400 text-xs mt-2">{error}</p>}

            <p className="text-xs mt-3">
              Don’t have an account?
              <Link
                to="/SignupPage"
                className="text-xs ml-2 text-blue-500 font-semibold hover:underline"
              >
                Sign Up
              </Link>
            </p>
          </div>
        </div>
      </section>
    </div>
  );
}

export default LoginInputs;
