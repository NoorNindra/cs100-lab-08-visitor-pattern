#ifndef __ITERATOR_TESTS_HPP__
#define __ITERATOR_TESTS_HPP__

#include <stdlib.h>

#include "gtest/gtest.h"

#include "iterator.hpp"
#include "visitor.hpp"
#include "add.hpp"

TEST(IteratorTest, AddIterate) {
	Op* one = new Op(1);
	Op* five = new Op(5);
	Add* add = new Add(one, five);

	Iterator* iter = add->create_iterator();
	iter->first();

        EXPECT_EQ(iter->current()->evaluate(), 1);

        iter->next();

        EXPECT_EQ(iter->current()->evaluate(), 5);

	//CountVisitor* vis = new Visitor();
	//iter->accept(vis);
	
	//EXPECT_EQ(vis->op_count, 2);
}

#endif //__ITERATOR_TESTS_HPP__
