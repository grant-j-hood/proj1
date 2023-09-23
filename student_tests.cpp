#define CATCH_CONFIG_MAIN            // this line tells Catch to provide a main() function
//#define CATCH_CONFIG_COLOUR_NONE    // this line avoids problems due to color-coding the output
#include "catch.hpp"

#include "ArrayBag.h" 

// The following set of tests needs to be expanded

TEST_CASE("Test an empty bag of integers", "[ArrayBag]")
{
    ArrayBag<int> b;
    REQUIRE(b.isEmpty()); 
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(!b.contains(5));
}

TEST_CASE("Test an bag of strings", "[ArrayBag]")
{
    ArrayBag<std::string> b;
    REQUIRE(b.isEmpty()); 
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.add("Hello"));
    REQUIRE(b.contains("Hello"));
}

TEST_CASE("Test ArrayBag flattening", "[ArrayBag]") {
    ArrayBag<int> bag;

    SECTION("Add items to the bag") {
        bag.add(2);
        bag.add(9);
        bag.add(17);
        bag.add(9);
        bag.add(17);
        bag.add(9);


        REQUIRE(bag.getCurrentSize() == 6);
    }

    SECTION("Flatten the bag") {
        bag.add(2);
        bag.add(9);
        bag.add(17);
        bag.add(9);
        bag.add(17);
        bag.add(9);
  

        bool result = bag.flatten();

        REQUIRE(result == true);
        REQUIRE(bag.getCurrentSize() == 3); // After flattening, there should be 3 unique items

        // Check for the presence of specific items
        REQUIRE(bag.contains(2));
        REQUIRE(bag.contains(9));
        REQUIRE(bag.contains(17));

        // Check the frequencies of specific items
        REQUIRE(bag.getFrequencyOf(2) == 1);
        REQUIRE(bag.getFrequencyOf(9) == 1);
        REQUIRE(bag.getFrequencyOf(17) == 1);
    }
}

