#include "RightAngled.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
#include <math.h>
#define PI 3.14159265

using namespace std;

bool RightAngled::Init(int a, int b, int c)
{
    int d1 = a;
    int d2 = b;
    int d3 = c;

    if(b > d1)
    {
        d1 = b;
        d2 = a;
    }
    if(c > d1)
    {
        d1 = c;
        d2 = a;
        d3 = b;
    }

    if ((d1*d1) == (d2*d2 + d3*d3))
    {
        return true;
    }
    else
    {
        cout << "Wrong arguments to init!" << endl;
        return false;
    }
}

void RightAngled::Read(Triangle& triangle)
{
    int s1, s2, s3;
    do
    {
        cout << "Set the sides:" << endl;
        cout << "a = "; cin >> s1;
        cout << "b = "; cin >> s2;
        cout << "c = "; cin >> s3;
    }
    while(!Init(s1, s2, s3));
    triangle.set_a(s1);
    triangle.set_b(s2);
    triangle.set_c(s3);
}

void RightAngled::Display(Triangle& triangle)
{
    int botton;
    do
    {
        cout << "MENU:\n1 - angles\n2 - perimeter\n3 - area\n4 - EXIT" << endl;
        cin >> botton;
        switch(botton)
        {
            case 1:
                triangle.angles();
                break;
                
            case 2:
                cout << "Perimeter is ";
                cout << triangle.perimeter() << endl;
                break;
        
            case 3:
                cout << "Area is ";
                area_calculate(triangle);
                cout << get_area() << endl;
                break;
                
            case 4:
                cout << "Program is terminated" << endl;
                break;
        }
    }
    while(botton != 4);
}

void RightAngled::area_calculate(Triangle& triangle)
{
    double p = triangle.perimeter() / 2;
    int s1 = triangle.get_a();
    int s2 = triangle.get_b();
    int s3 = triangle.get_c();
    
    double s = sqrt(p * (p - s1) * (p - s2) * (p - s3));
    set_area(s);
}


void RightAngled::Triangle::angles()
{
    int a = get_a();
    int b = get_b();
    int c = get_c();

    double d1 = a;
    double d2 = b;
    double d3 = c;

    if(b > d1)
    {
        d1 = b;
        d2 = a;
    }
    if(c > d1)
    {
        d1 = c;
        d2 = a;
        d3 = b;
    }
    
    double alfa = 90;
    double be = d2 / d1;
    double ga = d3 / d1;
    double beta = asin(be) * 180.0 / PI;;
    double gama = asin(ga) * 180.0 / PI;;
    alfa = round(alfa);
    beta = round(beta);
    gama = round(gama);
    
    string alfa_str = toString(alfa);
    string beta_str = toString(beta);
    string gama_str = toString(gama);

    cout << "Angles value: " << alfa_str << ", " << beta_str << ", " << gama_str << endl;
    
}

int RightAngled::Triangle::perimeter()
{
    int perimeter = get_a() + get_b() + get_c();
    return perimeter;
}


string RightAngled::Triangle::toString(int a)
{
    stringstream ss1;
    ss1 << a;
    string str1 = ss1.str();
    return str1 + "°";
}

