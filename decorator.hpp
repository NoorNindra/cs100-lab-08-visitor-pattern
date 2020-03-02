#ifndef __DECORATOR_HPP__
#define __DECORATOR_HPP__

#include <string>
#include <math.h>

#include "base.hpp"

class Decorator : public Base {
public:
    /* Constructors */
    Decorator() : Base() { }
    
    /* Pure Virtual Functions */
    virtual double evaluate() = 0;
    virtual std::string stringify() = 0;
};

#endif //__DECORATOR_HPP__

