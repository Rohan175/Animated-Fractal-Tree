#include "rsGraphics.h"
#include<graphics.h>
#include<iostream>
#include<cmath>
#include<pthread.h>
using namespace std;
#define PI 3.14

void* mThread(void*);

float angle = 0.7,lenChange=0.7,recur=0;
bool shouldLoop = false;


void tree(Point p1, float len,int diff,bool left){

    if(len < 10) return;
    Point p2(p1.x,p1.y-len*lenChange);

    l(p1,p2,GREEN);
    cout <<  "Before GREEN-> " << p2  << "  diff : " << diff<< endl;
    if(diff != 0){
        if(!left)
            p2 = p1+rotatePoint(p2-p1,-angle);
        else
            p2 = p1+rotatePoint(p2-p1,angle);
    }

    l(p1,p2,RED);


    cout << "After RED-> " << p2 << endl;
    Point rotatedP2;
    rotatedP2 = p1+rotatePoint(p2-p1,angle);
    l(p1,rotatedP2,MAGENTA);

    tree(rotatedP2,len*lenChange,rotatedP2.x - p1.x,true);
    rotatedP2 = p1+rotatePoint(p2-p1,-angle);
    l(p1,rotatedP2,CYAN);
    tree(rotatedP2,len*lenChange,rotatedP2.x - p1.x,false);


}



void tree2(Point p1, float len,Point oldP,int height){
    //if(recur++ > 7) return;

    if(len <2) return;
    Point p2(p1.x+len*lenChange,p1.y);
    cout << "Green => Before Rotation " << p2;
    l(p1,p2,GREEN);

    float normalizedAngle = findAngleBtnTwoPoints(oldP,p1);

    p2 = p1+rotatePoint(p2-p1,normalizedAngle);
    cout << "Red => Before Rotation" << p2 << endl;
    l(p1,p2,RED);


    //cout << "After -> " << p2 << endl;
    Point rotatedP2;
    rotatedP2 = p1+rotatePoint(p2-p1,angle);
    l(p1,rotatedP2);
    tree2(rotatedP2,len*lenChange,p1,++height);

    rotatedP2 = p1+rotatePoint(p2-p1,-angle);
    l(p1,rotatedP2);
    tree2(rotatedP2,len*lenChange,p1,++height);


}

struct dataForThread{
    Point p1; float len,lenChange;Point rotatedP2;
    dataForThread(Point p1, float len,Point rotatedP2,float lenChange){
        this->p1.x=p1.x;
        this->p1.y=p1.y;
        this->len=len;
        this->rotatedP2.x = rotatedP2.x;
        this->rotatedP2.y = rotatedP2.y;
        this->lenChange = lenChange;
    }
};



void treeThread(Point p1, float len,Point oldP){

    if(len <2) return;
    Point p2(p1.x+len*lenChange,p1.y);
    cout << "Green => Before Rotation " << p2;
    l(p1,p2,GREEN);

    float normalizedAngle = findAngleBtnTwoPoints(oldP,p1);

    p2 = p1+rotatePoint(p2-p1,normalizedAngle);
    cout << "Red => Before Rotation" << p2 << endl;
    l(p1,p2,RED);


    //cout << "After -> " << p2 << endl;
    Point rotatedP2;
    rotatedP2 = p1+rotatePoint(p2-p1,angle);

    pthread_t tid1,tid2;

    struct dataForThread mData(p1,len,rotatedP2,lenChange);
    pthread_create(&tid1, NULL, mThread, (void *)&mData);

    rotatedP2 = p1+rotatePoint(p2-p1,-angle);

    struct dataForThread mData2(p1,len,rotatedP2,lenChange);
    pthread_create(&tid2, NULL, mThread, (void *)&mData2);
}

void* mThread (void* data){

    struct dataForThread* d = (struct dataForThread *)data;
    cout << "Hello1";
    l(d->p1,d->rotatedP2);
    cout << "Hello2";
    treeThread(d->rotatedP2,d->len*d->lenChange,d->p1);
    cout << "Hello";
    return data;
}
void buildTree(){

    cout << " Size : " << getmaxx() << " x " << getmaxy() << endl;
    float mx = getmaxx()/2.0;
    float my = getmaxy();
    int len = 100;

    Point p1(mx,my,"oldP1"),p2(mx,my-len,"p2->1");
    l(p1,p2);
    treeThread(p2,len,p1);
    //tree2(p2,len,p1,0);
/*
    do{
        cleardevice();
        //lineWithData(p1,p2,"0");

        //normalizedLineTest();
        //tree(p2,len,p2.x-p1.x,true);

        l(p1,p2);
        cout << p2;
        tree2(p2,len,p1,0);
        tree2(p2,len*0.8,p1,0);
        tree2(p2,len*0.6,p1,0);
        tree2(p2,len*0.3,p1,0);
        delay(1000);
        angle+=0.1;
    }while(!kbhit() && shouldLoop);
8=*/
}
