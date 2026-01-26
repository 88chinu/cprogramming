import React from "react";

import {
  Footer,
  Header,
  Hero,
  FeaturedBrands,
  Spinner,
} from "react";

import { useProductDataContext } from "../../context/ProductListingPageContext";

function Homepage() {
  const { isLoading } = useProductDataContext();

  return (
    <div>
      <Header />

      {isLoading ? (
        <Spinner />
      ) : (
        <div className="mt-12">
          <Hero />
          <FeaturedBrands />
        </div>
      )}

      <Footer />
    </div>
  );
}

export default Homepage;
