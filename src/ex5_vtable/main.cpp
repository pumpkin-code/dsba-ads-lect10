/*! \file       main.cpp
 *  \author     Sergey Shershakov
 *  \version    0.2
 *  \date       18.02.2020
 *
 *  vtable example
 */

#include <iostream>


class Base {
public:
    virtual ~Base()
    {
        std::cout << "~Base()\n";
    }
public:
    // regular function
    int regFun();

    virtual void foo();
    virtual void bar();
};

void Base::foo()
{
    std::cout << "Base::foo() working" << "\n";
}

void Base::bar()
{
    std::cout << "Base::bar() working" << "\n";
}

int Base::regFun()
{
    std::cout << "Base::regFun() working" << "\n";
    return 42;
}


class Derived : public Base {
public:
    virtual ~Derived()
    {
        std::cout << "~Derived()\n";
    }
public:
  void foo() override;
};

void Derived::foo()
{
  std::cout << "Derived::foo() overidden variant working" << "\n";
}


void demo1()
{
    Base* b1 = new Base();
    Base* b2 = new Derived();

    b1->foo();
    b2->foo();

    delete b2;
    delete b1;
}


void demo2()
{
    std::cout << "Destructors demo\n";
    {
        Base b;
        Derived d;
    }

    Base* b1 = new Base();
    delete b1;

    Base* b2 = new Derived();
    delete b2;



}



int main()
{
    demo1();
    demo2();
    std::cout << "\n\n";
    return 0;
}
