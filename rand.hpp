#ifndef __RAND_HPP__
#define __RAND_HPP__

#include <stdlib.h>

#include "base.hpp"

class Rand : public Base {
	public:
		Rand() : Base() {
			object = new Op(rand() % 100);
                        it = create_iterator();
		}
		
		virtual double evaluate() {
			return object->evaluate();
		}

		virtual std::string stringify() {
			return object->stringify();
		}
                virtual Iterator* create_iterator() {return new NullIterator(this);}
        	virtual Base* get_left() {return nullptr;}
        	virtual Base* get_right() {return nullptr;}
		void accept(CountVisitor* cv) { cv->visit_rand(); }
	private:
		Base* object;
                Iterator* it;
};

#endif //__RAND_HPP__
