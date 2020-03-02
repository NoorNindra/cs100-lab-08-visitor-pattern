#ifndef __PAREN_HPP__
#define __PAREN_HPP__

class Paren : public Decorator
{
	public:
		/* Constructor */
		Paren(Base* e) {exp = e;}
		
		/* Virtual Functions */
		virtual double evaluate() {}

		virtual std::string stringify()
		{
			return "(" + exp->stringify() + ")";
		}
	private:
		Base* exp;
};

#endif //__PAREN_HPP__
