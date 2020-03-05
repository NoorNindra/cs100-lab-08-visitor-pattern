#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "visitor.hpp"

class Op : public Base {
public:
    Op(double value) : Base() { number = value; it = create_iterator(); }
    virtual double evaluate() { return number; }
    virtual std::string stringify() { return std::to_string(number); }
    virtual Iterator* create_iterator() {return new NullIterator(this);}
    virtual Base* get_left() {return nullptr;}
    virtual Base* get_right() {return nullptr;}

    void accept(CountVisitor* cv) { cv->visit_op(); } 
private:
    double number;
    Iterator* it;
};

#endif //__OP_HPP__
