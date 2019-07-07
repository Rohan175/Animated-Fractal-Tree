#include "point.h"
#include<graphics.h>
#include<iostream>
#include<cmath>
using namespace std;
int delayAmount = 10;

void l(Point p1,Point p2,int color){
        //cout << color << endl;
        double dx = p2.x - p1.x;
        double dy = p2.y - p1.y;
        double steps = (abs(dx)>abs(dy)) ? abs(dx) : abs(dy);
        double xIncr = dx/steps;
        double yIncr = dy/steps;
        Point p = p1;
        int xx = round(p.x);
        int yy = round(p.y);
        //cout << xx << " "  << yy << " ";
        putpixel(xx, yy, color);
        //delay(delayAmount);
        for(int i = 0; i<steps; i++)
        {
            delay(delayAmount);
            p.x += xIncr;
            p.y += yIncr;
            xx = round(p.x);
            yy = round(p.y);
            putpixel(xx, yy, color);
        }
        //delayAmount++;
        /*
        double delY = (p2.y - p1.y);
        double delX = (p2.x - p1.x);
       // assert(delX >= delY);
        double d = 2*delY - delX;
        Point p = p1;
        cout << p << p2 << delY << " " << delX << " ";
        while(p.x <= p2.x)
        {

            int xx = round(p.x);
            int yy = round(p.y);
            cout << xx << " "  << yy << " ";
            putpixel(xx, yy, WHITE);
            if(d<=0)
            {
                d += 2*delY;
            }
            else
            {
                d += 2*(delY - delX);
                p.y++;
            }
            p.x++;
        }

*/

    //line(p1.x,p1.y,p2.x,p2.y);
}

void l(Point p1,Point p2) { l(p1,p2,WHITE); }


void lineWithData(Point p1, Point p2,const char* c){
    int color = WHITE;
    Point mid = (p1+p2)/2;
    int diff = 12;
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    outtextxy(mid.x-1,mid.y,c);

    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double steps = (abs(dx)>abs(dy)) ? abs(dx) : abs(dy);
    double xIncr = dx/steps;
    double yIncr = dy/steps;
    Point p = p1;
    int xx = round(p.x);
    int yy = round(p.y);
    //cout << xx << " "  << yy << " ";
    putpixel(xx, yy, color);
    double stepsNew = (steps/2)-diff;
    for(int i = 0; i<stepsNew; i++)
    {
        delay(delayAmount);
        p.x += xIncr;
        p.y += yIncr;
        xx = round(p.x);
        yy = round(p.y);
        putpixel(xx, yy, color);
    }
    p.x+=diff*xIncr;
    p.y+=diff*yIncr;
    for(int i = 0; i<stepsNew; i++)
    {
        delay(delayAmount);
        p.x += xIncr;
        p.y += yIncr;
        xx = round(p.x);
        yy = round(p.y);
        putpixel(xx, yy, color);
    }

}
void rotateLinePivot(Point p1, Point p2,float angle){

    Point translatedP = p2 - p1;

    translatedP = p1 + rotatePoint(translatedP,angle);

    line(p1.x,p1.y,translatedP.x,translatedP.y);
}

void rotateLineCenter(Point p1, Point p2,float angle){
    Point midP = (p1 + p2)/2;

    Point translatedP1 = p1 - midP,translatedP2 = p2 - midP;

    translatedP1 = midP + rotatePoint(translatedP1,angle);
    translatedP2 = midP + rotatePoint(translatedP2,angle);

    line(translatedP1.x,translatedP1.y,translatedP2.x,translatedP2.y);
}

 int lineRotation(){
    cout << "HI0";
    int gdriver =  DETECT, gmode;    float cx,cy;
    initgraph(&gdriver,&gmode,"");

    cx=getmaxx()/2.0;
    cy=getmaxy()/2.0;
    Point p1(cx-20,cy-20),p2(cx+20,cy+20);
    line(p1.x,p1.y,p2.x,p2.y);
    float angle = 0.0;

    while(!kbhit()){
        rotateLineCenter(p1,p2,angle);
        angle+=3.14/40;
        delay(100);
    }

    getch();
    closegraph();
    return 0;
}


