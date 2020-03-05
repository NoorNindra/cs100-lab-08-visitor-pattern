#ifndef __ABS_HPP__
#define __ABS_HPP__

#include "decorator.hpp"

class Abs : public Decorator
{
	public:
		/* Constructors */
		Abs(Base* b) {function = b; it = create_iterator(); } 
		
		/* Virtual Functions */
		virtual double evaluate()
		{
			return abs(function->evaluate());
		}

		virtual std::string stringify() {}

		virtual Iterator* create_iterator() { return new UnaryIterator(this); }
		virtual Base* get_left() { return function; }
		virtual Base*  get_right() { return nullptr; }
		void accept(CountVisitor* cv) { cv->visit_abs(); }
	private:
		Base* function;
		Iterator* it;
};

#endif //__ABS_HPP__
