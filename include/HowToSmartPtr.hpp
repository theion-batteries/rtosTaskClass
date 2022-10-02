#include <iostream>
#include <memory>
struct Base 
{
    virtual ~Base() { }

    virtual void SayHello()
    {
        std::cout << "Hello from Base.\n";
    }
};

struct Derived : public Base
{
    void SayHello() override
    {
        std::cout << "Hello from Derived.\n";
    }
};

class Rectangle {
    int length;
    int breadth;
 
public:
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
 
    int area()
    {
        return length * breadth;
    }
};
void test_unique_ptr()
{
  std::unique_ptr<Rectangle> P1(new Rectangle(20, 5));
    std::cout << "unique ptr p1 call area " << P1->area() << std::endl; // This'll print 50
 
    // std::unique_ptr<Rectangle> P2(P1);
    std::unique_ptr<Rectangle> P2;
    P2 = move(P1);
 
    // This'll print 50
    std::cout << "move ownership to unique ptr p2 "<<P2->area() << std::endl;
 
    // std::cout<<P1->area()<<std::endl;
} 
void test_shared_ptr()
{
 
    std::shared_ptr<Rectangle> P1(new Rectangle(10, 50));
    // This'll print 50
    std::cout <<"shared ptr p1 call area " << P1->area() << std::endl;
 
    std::shared_ptr<Rectangle> P2;
    P2 = P1;
 
    // This'll print 50
    std::cout <<"cretaed a second shared ptr p2 pointing to same object "<<  P2->area() << std::endl;
 
    // This'll now not give an error,
    std::cout <<"p1 still pointing to object "<< P1->area() << std::endl;
 
    // This'll also print 50 now
    // This'll print 2 as Reference Counter is 2
    std::cout << "p1 has incremented reference to 2 after sharing object" << P1.use_count() << std::endl;
 
}