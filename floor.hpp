#ifndef __FLOOR_HPP__
#define __FLOOR_HPP__

#include <string>
#include <math.h>

#include "decorator.hpp"
#include "base.hpp"

class Floor : public Decorator {
public:
    /* Constructors */
    Floor(Base* b) { function = b; it = create_iterator(); }
    
    /* Pure Virtual Functions */
    virtual double evaluate() {
        return floor(function->evaluate());
    }
    
    
    virtual std::string stringify() {}

    virtual Iterator* create_iterator() { return new UnaryIterator(this); }
    virtual Base* get_left() { return function; }
    virtual Base* get_right() { return nullptr; }
    void accept(CountVisitor* cv) { cv->visit_floor(); }
private:
    Base* function;
    Iterator* it;
};

#endif //__FLOOR_HPP__



