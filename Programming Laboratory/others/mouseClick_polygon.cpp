#include<graphics.h>
#include<iostream>
#include<stdio.h>
#include <dos.h>
using namespace std;
int main()
{
initwindow(500,500);
int x,y;
do
{
    if(ismouseclick(WM_LBUTTONDOWN))
       {
    getmouseclick(WM_LBUTTONDOWN, x, y);circle(x,y,40);
       }
}while(!ismouseclick(WM_RBUTTONDOWN));
exit(0);
getch();
}



