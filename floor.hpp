#ifndef __FLOOR_HPP__
#define __FLOOR_HPP__

#include <string>
#include <math.h>

#include "decorator.hpp"
#include "base.hpp"

class Floor : public Decorator {
public:
    /* Constructors */
    Floor(Base* b) { function = b; }
    
    /* Pure Virtual Functions */
    virtual double evaluate() {
        return floor(function->evaluate());
    }
    
    
    virtual std::string stringify() {}
private:
    Base* function;
};

#endif //__FLOOR_HPP__



