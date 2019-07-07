#include "rsGraphics.h"
#include<windows.h>

#include<pthread.h>


float left, top, right, bottom;

struct mline{

    Point p1,p2;

};

void* threadMethod1(void *data)
{
  struct mline* d = (struct mline *)data;
  l(d->p1,d->p2);
  pthread_exit(NULL);
}


int main(){

    int gdriver =  DETECT, gmode;
    initgraph(&gdriver,&gmode,"");

    Point c(getmaxx()/2,getmaxy()/2),p1(c.x,c.y-50),p2(c.x+50,c.y);
    /*
    pthread_t tid1;
    struct mline l1;
    l1.p1=p1;
    l1.p2=p2;

    if( pthread_create(&tid1, NULL, threadMethod1, (void *)&l1) != 0 )
        std::cout << "Failed to create thread1\n";

    l(c,p2);
    pthread_join(tid1,NULL);
    */
    buildTree();

    getch();
    closegraph();
    return 0;

}
