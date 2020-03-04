#ifndef __TRUNC_HPP__
#define __TRUNC_HPP__

#include <string>
#include <math.h>

#include "decorator.hpp"
#include "base.hpp"

class Trunc : public Decorator {
public:
    /* Constructors */
    Trunc(Base* b) { function = b; it = create_iterator(); }
    
    /* Pure Virtual Functions */
    virtual double evaluate() {}
    
    virtual std::string stringify() {
        return std::to_string(trunc(function->evaluate()));
    }
    
    virtual Iterator* create_iterator() {return new UnaryIterator(this);}
    virtual Base* get_left() {return function;}
    virtual Base* get_right() {return nullptr;}
    
private:
    Base* function;
    Iterator* it;
};

#endif //__TRUNC_HPP__



