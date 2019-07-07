#ifndef rPoint_H
#define rPOint_H
#include<iostream>
class Point{
    public:
        float x ,y;
        std::string name;
    Point();
    Point(float x, float y);
    Point(float x, float y,std::string name);
};
Point rotatePoint(Point p,float angle);
float findAngleBtnTwoPoints(Point p1,Point p2);
std::ostream &operator<<(std::ostream & Str, Point const & v);
Point operator+ (Point const &c1, Point const &c2);
Point operator- (Point const &c1, Point const &c2);
Point operator/ (Point const &c1, int const &c2);

#endif

