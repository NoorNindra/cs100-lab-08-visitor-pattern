#ifndef __COUNTVISITOR_HPP__
#define __COUNTVISTIOR_HPP__



class CountVistor {

private:
	int ops;
	int rands;
	int adds;
	int subs;
	int mults;
	int divs;
	int pows;
	int ceils;
	int floors;
	int abs;
	int parens;
	int truncs;

public:
	CountVisitor();

	void visit_op();
	int op_count();
	void visit_rand();
        int rand_count();
	void visit_add();
        int add_count();
	void visit_sub();
        int sub_count();
	void visit_mult();
        int mult_count();
        void visit_div();
        int div_count();
        void visit_pow();
        int pow_count();
        void visit_ceil();
        int ceil_count();
        void visit_floor();
        int floor_count();
        void visit_abs();
        int abs_count();
        void visit_paren();
        int paren_count();
        void visit_trunc();
        int trunc_count();


};



#endif //__COUNTVISTOR_HPP__
