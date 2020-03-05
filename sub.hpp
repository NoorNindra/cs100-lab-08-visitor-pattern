#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

class Sub : public Base {
public:
    Sub(Base* obj1, Base* obj2) : Base() {
        object1 = obj1;
        object2 = obj2;
	it = create_iterator();
    }
    
    virtual double evaluate() {
        return object1->evaluate() - object2->evaluate();
    }
    
    virtual std::string stringify() { return object1->stringify() + " - " + object2->stringify();}

    virtual Iterator* create_iterator() { return new BinaryIterator(this); }
    virtual Base* get_left() { return object1; }
    virtual Base* get_right() { return object2; }
    void accept(CountVisitor* cv) { cv->visit_sub(); }
private:
    Base* object1;
    Base* object2;
    Iterator* it;
};

#endif //__SUB_HPP__

