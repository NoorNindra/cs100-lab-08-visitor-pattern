#ifndef __ITERATOR_TESTS_HPP__
#define __ITERATOR_TESTS_HPP__

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
#include "paren.hpp"
#include "trunc.hpp"

TEST(IteratorTest, AddIterate) {
	Op* one = new Op(1);
	Op* five = new Op(5);
	Add* add = new Add(one, five);

	Iterator* iter = add->create_iterator();
	iter->first();

        EXPECT_EQ(iter->current()->evaluate(), 1);

        iter->next();

        EXPECT_EQ(iter->current()->evaluate(), 5);
}

TEST(IteratorTest, AddSubIterate) {
        Op* one = new Op(1);
        Op* five = new Op(5);
        Op* seven = new Op(7);
        Add* add = new Add(one, five);
        Sub* sub = new Sub(seven, add);

        Iterator* iter = sub->create_iterator();
        iter->first();

        EXPECT_EQ(iter->current()->evaluate(), 7);

        iter->next();

        EXPECT_EQ(iter->current()->evaluate(), 6);

        Iterator* it = iter->current()->create_iterator();

        iter->next();

        EXPECT_EQ(iter->is_done(), true);

        it->first();

        EXPECT_EQ(it->current()->evaluate(), 1);

        it->next();

        EXPECT_EQ(it->current()->evaluate(), 5);

        it->next();

        EXPECT_EQ(it->is_done(), true);
}


TEST(IteratorTest, CeilIterate) {
        Op* num = new Op(2.4);
        Ceil* ceil = new Ceil(num);

        Iterator* iter = ceil->create_iterator();
        iter->first();

        EXPECT_EQ(iter->current()->evaluate(), 2.4);

        iter->next();

        EXPECT_EQ(iter->is_done(), true);

}

#endif //__ITERATOR_TESTS_HPP__
