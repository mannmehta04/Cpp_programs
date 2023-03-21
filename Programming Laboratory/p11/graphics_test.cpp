#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
int main(){
   int gd = DETECT, gm;
   initgraph(&gd, &gm, NULL);
   circle(40, 40, 30);
   delay(40000);
   closegraph();
   return 0;
}