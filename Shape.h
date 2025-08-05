#ifndef Shape_h
#define Shape_h

class Shape{
    public:
    Shape();
    Shape(const Shape& other) {};
    Shape* clone();
    ~Shape();
};
#endif