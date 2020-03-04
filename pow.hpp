#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <math.h>

class Pow : public Base {
public:
    Pow(Base* obj1, Base* obj2) : Base() {
        object1 = obj1;
        object2 = obj2;
        it = create_iterator();
    }
    
    virtual double evaluate() {
        return pow ( object1->evaluate() , object2->evaluate() );
    }
    
    virtual std::string stringify() { return object1->stringify() + " ** " + object2->stringify(); }
    
    virtual Iterator* create_iterator() {return new BinaryIterator(this);}
    virtual Base* get_left() {return object1;}
    virtual Base* get_right() {return object2;}

private:
    Base* object1;
    Base* object2;
    Iterator* it;
};

#endif //__POW_HPP__


