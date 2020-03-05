#ifndef __CEIL_HPP__
#define __CEIL_HPP__

#include <string>
#include <math.h>

#include "decorator.hpp"
#include "base.hpp"

class Ceil : public Decorator {
public:
    /* Constructors */
    Ceil(Base* b) { function = b; it = create_iterator(); }
    
    /* Pure Virtual Functions */
    virtual double evaluate() {
        return ceil(function->evaluate());
    }
    
    virtual std::string stringify() {}

    virtual Iterator* create_iterator() {return new UnaryIterator(this);}
    virtual Base* get_left() {return function;}
    virtual Base* get_right() {return nullptr;}
    void accept(CountVisitor* cv) { cv->visit_ceil(); }
private:
    Base* function;
    Iterator* it;
};

#endif //__CEIL_HPP__


