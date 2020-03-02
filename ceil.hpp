#ifndef __CEIL_HPP__
#define __CEIL_HPP__

#include <string>
#include <math.h>

#include "decorator.hpp"
#include "base.hpp"

class Ceil : public Decorator {
public:
    /* Constructors */
    Ceil(Base* b) { function = b; }
    
    /* Pure Virtual Functions */
    virtual double evaluate() {
        return ceil(function->evaluate());
    }
    
    
    virtual std::string stringify() {}
private:
    Base* function;
};

#endif //__CEIL_HPP__


