#ifndef __VISITOR_TESTS_HPP__
#define __VISITOR_TESTS_HPP__

#include <stdlib.h>

#include "gtest/gtest.h"

#include "iterator.hpp"
#include "visitor.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "ceil.hpp"
#include "abs.hpp"
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

#endif //__VISITOR_TEST_HPP__
