#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "limited_size_bag.tpp"


// force template expansion for ints
template class LimitedSizeBag<int>;

TEST_CASE("Test 1", "[LimitedSizeBag]") {
LimitedSizeBag<int> limitbag;
REQUIRE(limitbag.getCurrentSize() == 10);
REQUIRE(limitbag.fillNum() == 0);
//placing in value 15
int a = 15;
int & input = a;
REQUIRE(true == limitbag.add(input));
};

TEST_CASE("Test 2", "[LimitedSizeBag]") {
LimitedSizeBag<int> bag;
int a = 1;
int b = 2;
int c = 3;
int d = 4;
int & fill1 = a;
int & fill2 = b;
int & fill3 = c;
int & fill4 = d;

bag.add(fill1);
bag.add(fill2);
bag.add(fill3);

REQUIRE(bag.remove(fill4) == false);
REQUIRE(bag.remove(fill3) == true);

REQUIRE(bag.getCurrentSize() == 10);

REQUIRE(bag.isEmpty() == false);

}
