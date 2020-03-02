#ifndef __ABS_HPP__
#define __ABS_HPP__

#include "decorator.hpp"

class Abs : public Decorator
{
	public:
		/* Constructors */
		Abs(Base* b) {function = b;} 
		
		/* Virtual Functions */
		virtual double evaluate()
		{
			return abs(function->evaluate());
		}

		virtual std::string stringify() {}

	private:
		Base* function;
};

#endif //__ABS_HPP__
