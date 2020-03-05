#ifndef __VISITOR_TESTS_HPP__
#define __VISITOR_TESTS_HPP__

#include <stdlib.h>

#include "gtest/gtest.h"

#include "iterator.hpp"
#include "visitor.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "ceil.hpp"
#include "floor.hpp"
#include "abs.hpp"
#include "trunc.hpp"
#include "paren.hpp"

TEST(VisitorTest, OpVisit) {
	Op* one = new Op(1);
        Paren* dummyNode = new Paren(one);

        PreorderIterator* it = new PreorderIterator(dummyNode);
        CountVisitor* cv = new CountVisitor();

        it->first();
        while (!it->is_done()) {
            it->current()->accept(cv);
	    it->next();
        }
	
	EXPECT_EQ(cv->op_count(), 1);

}

TEST(VisitorTest, AddVisit) {
        Op* one = new Op(1);
        Add* add = new Add(one, one);
        Paren* dummyNode = new Paren(add);

        PreorderIterator* it = new PreorderIterator(dummyNode);
        CountVisitor* cv = new CountVisitor();

        it->first();
        while (!it->is_done()) {
            it->current()->accept(cv);
            it->next();
        }

        EXPECT_EQ(cv->add_count(), 1);

}

TEST(VisitorTest, SubVisit) {
	Op* one = new Op(1);
	Op* five = new Op(5);
        Sub* sub = new Sub(five, one);
        Paren* dummyNode = new Paren(sub);

        PreorderIterator* it = new PreorderIterator(dummyNode);
        CountVisitor* cv = new CountVisitor();

        it->first();
        while (!it->is_done()) {
            it->current()->accept(cv);
            it->next();
        }

        EXPECT_EQ(cv->sub_count(), 1);
}

TEST(VisitorTest, MultVisit) {
	Op* one = new Op(1);
        Mult* mult = new Mult(one, one);
        Paren* dummyNode = new Paren(mult);

        PreorderIterator* it = new PreorderIterator(dummyNode);
        CountVisitor* cv = new CountVisitor();

        it->first();
        while (!it->is_done()) {
            it->current()->accept(cv);
            it->next();
        }

        EXPECT_EQ(cv->mult_count(), 1);
}

TEST(VisitorTest, DivVisit) {
	Op* one = new Op(1);
        Div* div = new Div(one, one);
        Paren* dummyNode = new Paren(div);

        PreorderIterator* it = new PreorderIterator(dummyNode);
        CountVisitor* cv = new CountVisitor();

        it->first();
        while (!it->is_done()) {
            it->current()->accept(cv);
            it->next();
        }

        EXPECT_EQ(cv->div_count(), 1);
}

TEST(VisitorTest, RandVisit) {
        Rand* rand = new Rand();
        Paren* dummyNode = new Paren(rand);

        PreorderIterator* it = new PreorderIterator(dummyNode);
        CountVisitor* cv = new CountVisitor();

        it->first();
        while (!it->is_done()) {
            it->current()->accept(cv);
            it->next();
        }

        EXPECT_EQ(cv->rand_count(), 1);

}

TEST(VisitorTest, PowVisit) {
        Op* two = new Op(2);
        Op* three = new Op(3);
        Pow* pow = new Pow(two, three);
        Paren* dummyNode = new Paren(pow);

        PreorderIterator* it = new PreorderIterator(dummyNode);
        CountVisitor* cv = new CountVisitor();

        it->first();
        while (!it->is_done()) {
            it->current()->accept(cv);
            it->next();
        }

        EXPECT_EQ(cv->pow_count(), 1);

}

TEST(VisitorTest, AbsVisit) {
	Op* one = new Op(1);
        Abs* abs = new Abs(one);
        Paren* dummyNode = new Paren(abs);

        PreorderIterator* it = new PreorderIterator(dummyNode);
        CountVisitor* cv = new CountVisitor();

        it->first();
        while (!it->is_done()) {
            it->current()->accept(cv);
            it->next();
        }

        EXPECT_EQ(cv->abs_count(), 1);
}

TEST(VisitorTest, CeilVisit) {
        Op* num = new Op(2.4);
        Ceil* ceil = new Ceil(num);
        Paren* dummyNode = new Paren(ceil);

        PreorderIterator* it = new PreorderIterator(dummyNode);
        CountVisitor* cv = new CountVisitor();

        it->first();
        while (!it->is_done()) {
            it->current()->accept(cv);
            it->next();
        }

        EXPECT_EQ(cv->ceil_count(), 1);

}

TEST(VisitorTest, FloorVisit) {
	Op* num = new Op(2.4);
        Floor* floor = new Floor(num);
        Paren* dummyNode = new Paren(floor);

        PreorderIterator* it = new PreorderIterator(dummyNode);
        CountVisitor* cv = new CountVisitor();

        it->first();
        while (!it->is_done()) {
            it->current()->accept(cv);
            it->next();
        }

        EXPECT_EQ(cv->floor_count(), 1);
}

TEST(VisitorTest, TruncVisit) {
        Op* one = new Op(1);
	Op* two = new Op(2);
	Op* three = new Op(3);
        Add* add = new Add(one, two);
	Sub* sub = new Sub(add, three);
	Trunc* trunc = new Trunc(sub);
        Paren* dummyNode = new Paren(trunc);

        PreorderIterator* it = new PreorderIterator(dummyNode);
        CountVisitor* cv = new CountVisitor();

        it->first();
        while (!it->is_done()) {
            it->current()->accept(cv);
            it->next();
        }

        EXPECT_EQ(cv->trunc_count(), 1);

}

TEST(VisitorTest, ParenVisit) {
	Op* one = new Op(1);
        Paren* paren = new Paren(one);
        Paren* dummyNode = new Paren(paren);

        PreorderIterator* it = new PreorderIterator(dummyNode);
        CountVisitor* cv = new CountVisitor();

        it->first();
        while (!it->is_done()) {
            it->current()->accept(cv);
            it->next();
        }

        EXPECT_EQ(cv->paren_count(), 1);
}

TEST(VisitorTest, AddSubVisit) {
        Op* one = new Op(1);
	Op* two = new Op(2);
        Add* add = new Add(one, one);
	Sub* sub = new Sub(two, add);
	Sub* sub2 = new Sub(one, sub);
        Paren* dummyNode = new Paren(sub2);

        PreorderIterator* it = new PreorderIterator(dummyNode);
        CountVisitor* cv = new CountVisitor();

        it->first();
        while (!it->is_done()) {
            it->current()->accept(cv);
            it->next();
        }

        EXPECT_EQ(cv->add_count(), 1);
	EXPECT_EQ(cv->sub_count(), 2);

}

TEST(VisitorTest, MultDivVisit) {
        Op* one = new Op(1);
        Op* two = new Op(2);
        Mult* mult = new Mult(one, two);
        Div* div = new Div(two, two);
        Div* div2 = new Div(mult, div);
        Paren* dummyNode = new Paren(div2);

        PreorderIterator* it = new PreorderIterator(dummyNode);
        CountVisitor* cv = new CountVisitor();

        it->first();
        while (!it->is_done()) {
            it->current()->accept(cv);
            it->next();
        }

        EXPECT_EQ(cv->mult_count(), 1);
        EXPECT_EQ(cv->div_count(), 2);

}

TEST(VisitorTest, MultiplePowVisit) {
        Op* one = new Op(1);
        Op* two = new Op(2);
        Pow* pow = new Pow(two, two);
        Pow* pow2 = new Pow(pow, two);
        Pow* pow3 = new Pow(pow2, one);
        Paren* dummyNode = new Paren(pow3);

        PreorderIterator* it = new PreorderIterator(dummyNode);
        CountVisitor* cv = new CountVisitor();

        it->first();
        while (!it->is_done()) {
            it->current()->accept(cv); 
            it->next(); 
        }

        EXPECT_EQ(cv->pow_count(), 3);

}

TEST(VisitorTest, MultipleCeilVisit) {
        Op* one = new Op(1.9);
        Op* two = new Op(2.3);
        Ceil* ceil = new Ceil(one);
        Ceil* ceil2 = new Ceil(two);
        Add* add = new Add(ceil, ceil2);
        Paren* dummyNode = new Paren(add);

        PreorderIterator* it = new PreorderIterator(dummyNode);
        CountVisitor* cv = new CountVisitor();

        it->first();
        while (!it->is_done()) {
            it->current()->accept(cv);
            it->next();
        }

        EXPECT_EQ(cv->ceil_count(), 2);

}

TEST(VisitorTest, MultipleTruncVisit) {
        Op* one = new Op(1);
        Op* two = new Op(2);
        Mult* mult = new Mult(one, two);
        Div* div = new Div(two, two);
	Trunc* trunc = new Trunc(div);
        Div* div2 = new Div(mult, trunc);
	Trunc* trunc2 = new Trunc(div2);
        Paren* dummyNode = new Paren(trunc2);

        PreorderIterator* it = new PreorderIterator(dummyNode);
        CountVisitor* cv = new CountVisitor();

        it->first();
        while (!it->is_done()) {
            it->current()->accept(cv);
            it->next();
        }

        EXPECT_EQ(cv->trunc_count(), 2);

}

TEST(VisitorTest, MultipleSubVisit) {
	Op* negtwoPointfour = new Op(-2.4);
	Op* five = new Op(5);
	Abs* abs = new Abs(negtwoPointfour);
	Floor* floor = new Floor(abs);
	Sub* sub = new Sub(five, floor);
	Sub* sub2 = new Sub(five, sub);
	Paren* dummyNode = new Paren(sub2);

	PreorderIterator* it = new PreorderIterator(dummyNode);
	CountVisitor* cv = new CountVisitor();

	it->first();
	while (!it->is_done()) {
		it->current()->accept(cv);
		it->next();
	}
	
	EXPECT_EQ(cv->sub_count(), 2);
}

#endif //__VISITOR_TEST_HPP__
