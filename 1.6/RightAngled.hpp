#pragma once
#include <string>
#include <iostream>

using namespace std;

class RightAngled
{
private:
    double area;

    class Triangle
    {
    private:
        int a, b, c;
    public:
        void set_a(int value) { a = value; };
        void set_b(int value) { b = value; };
        void set_c(int value) { c = value; };
        
        int get_a() { return a; };
        int get_b() { return b; };
        int get_c() { return c; };
        
        void angles();
        int perimeter();
        string toString(int);
    };
    
    Triangle triangle;

public:
    void set_area(double value) { area = value; };
    double get_area() { return area; };
    
    bool Init(int a, int b, int c);
    void Read(Triangle& triangle);
    void Display(Triangle& triangle);
    
    void area_calculate(Triangle& triangle);
    void call()
        {
            Read(triangle);
            Display(triangle);
        }
};

