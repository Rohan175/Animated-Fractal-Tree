#include "point.h"
#include<iostream>
#include<cmath>
#include<graphics.h>
#define PI 3.14
using namespace std;

Point::Point(){x=0;y=0;}
Point::Point(float x, float y){
        this->x = x;
        this->y = y;
    }
Point::Point(float x, float y ,string name){
        this->x = x;
        this->y = y;
        this->name = name;
}


std::ostream & operator<<(std::ostream & Str, Point const & v) { cout << v.name << " -> x : " << v.x << "  y : " << v.y << endl;  return Str;}
Point operator + (Point const &c1, Point const &c2){return Point(c1.x + c2.x, c1.y + c2.y);}
Point operator - (Point const &c1, Point const &c2){return Point(c1.x - c2.x, c1.y - c2.y);}
Point operator / (Point const &c1, int const &c2){return Point(c1.x / c2, c1.y / c2);}


Point rotatePoint(Point p,float angle){
    Point rP;
    rP.x = p.x * cos(angle) - p.y * sin(angle);
    rP.y = p.x * sin(angle) + p.y * cos(angle);
    //cout << "Inside Rotation : " << cos(angle) << "sin " <<  sin(angle) << endl << p << rP ;
    return rP;
}


float findAngleBtnTwoPoints(Point p1,Point p2){
    Point sub = p2 - p1;
    float nAngle = atan2f(sub.y,sub.x);
    cout  <<  p1 << p2 <<"Angle " << nAngle/PI*180 << endl;
    return nAngle;
}


