#ifndef __PAREN_HPP__
#define __PAREN_HPP__

class Paren : public Decorator
{
	public:
		/* Constructor */
		Paren(Base* e) {exp = e; it = create_iterator(); }
		
		/* Virtual Functions */
		virtual double evaluate() {}

		virtual std::string stringify()
		{
			return "(" + exp->stringify() + ")";
		}

		virtual Iterator* create_iterator() { return new UnaryIterator(this); }
		virtual Base* get_left() { return exp; }
		virtual Base* get_right() { return nullptr; }
		void accept(CountVisitor* cv) { cv->visit_paren(); }
	private:
		Base* exp;
		Iterator* it;
};

#endif //__PAREN_HPP__
