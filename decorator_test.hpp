#ifndef __DECORATOR_TEST_HPP__
#define __DECORATOR_TEST_HPP__

#include <stdlib.h>

#include "gtest/gtest.h"

#include "ceil.hpp"
#include "abs.hpp"
#include "paren.hpp"
#include "trunc.hpp"
#include "floor.hpp"
#include "op.hpp"

TEST(CeilTest, CeilEvaluate) {
    Op* onePointFive = new Op(1.5);
    Ceil* round = new Ceil(onePointFive);
    EXPECT_EQ(round->evaluate(), 2);
}

TEST(AbsTest, AbsEvaluate) {
	Op* negFive = new Op(-5);
	Abs* abs = new Abs(negFive);
	EXPECT_EQ(abs->evaluate(), 5);
}

TEST(ParenTest, ParenStringify) {
	Op* five = new Op(5);
	Paren* paren = new Paren(five);
	EXPECT_EQ(paren->stringify(), "(5.000000)");
}

TEST(FloorTest, FloorEvaluate) {
	Op* tenPointSeven = new Op(10.7);
	Floor* floor = new Floor(tenPointSeven);
	EXPECT_EQ(floor->evaluate(), 10);
}

TEST(TruncTest, TruncStringify) {
	Op* three = new Op(3);
	Op* five = new Op(5);
	Add* add = new Add(three, five);
	Trunc* trunc = new Trunc(add);
	EXPECT_EQ(trunc->stringify(), "8.000000");
}

TEST(CeilAndAbsTest, CeilAndAbsEvaluate) {
	Op* negTwoPointSix = new Op(-2.6);
	Abs* abs = new Abs(negTwoPointSix);
	Ceil* ceil = new Ceil(abs);
	EXPECT_EQ(ceil->evaluate(), 3);
}

TEST(FloorAndTruncTest, FloorAndTruncEvalAndString) {
	Op* eightPointThree = new Op(8.3);
	Op* five = new Op(5);
	Op* two = new Op(2);
	Floor* floor = new Floor(eightPointThree);
	Sub* sub = new Sub(floor, five);
	Pow* pow = new Pow(sub, two);
	Trunc* trunc = new Trunc(pow);
	EXPECT_EQ(trunc->stringify(), "9.000000");
}

TEST(ParenAndTruncTest, ParenAndTruncStringify) {
	Op* six = new Op(6);
	Op* eight = new Op(8);
	Mult* mult = new Mult(six, eight);
	Trunc* trunc = new Trunc(mult);
	Pow* pow = new Pow(trunc, six);
	Paren* paren = new Paren(pow);
	EXPECT_EQ(paren->stringify(), "(48.000000 ** 6.000000)");
}	

#endif //__DECORATOR_TEST_HPP__

