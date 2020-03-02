#ifndef __TRUNC_HPP__
#define __TRUNC_HPP__

#include <string>
#include <math.h>

#include "decorator.hpp"
#include "base.hpp"

class Trunc : public Decorator {
public:
    /* Constructors */
    Trunc(Base* b) { function = b; }
    
    /* Pure Virtual Functions */
    virtual double evaluate() {}
    
    virtual std::string stringify() {
        return std::to_string(trunc(function->evaluate()));
    }
    
    
private:
    Base* function;
};

#endif //__TRUNC_HPP__



