
#ifndef RS_H
#define RS_H
#include "graphics.h"
#include "point.h"
void l(Point,Point);
void l(Point,Point,int);
void lineWithData(Point , Point ,const char*);
void rotateLinePivot(Point p1, Point p2,float angle);
void rotateLineCenter(Point p1, Point p2,float angle);
void lineRotation();


void buildTree();

#endif
