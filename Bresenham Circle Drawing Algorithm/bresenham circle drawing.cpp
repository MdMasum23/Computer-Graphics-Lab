#include<graphics.h>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;

void bresenhamCircle(int xc,int yc, int r)
{
    int x=0;
    int y=r;
    int p=3-2*r;
    while(x<=y)
    {
        putpixel(xc+x,yc+y,WHITE);
        putpixel(xc-x,yc+y,WHITE);
        putpixel(xc+x,yc-y,WHITE);
        putpixel(xc-x,yc-y,WHITE);
        putpixel(xc+y,yc+x,WHITE);
        putpixel(xc-y,yc+x,WHITE);
        putpixel(xc+y,yc-x,WHITE);
        putpixel(xc-y,yc-x,WHITE);

        if (p<0)
        {
            p=p+4*x+6;
        }
        else
        {
            p=p+4*(x-y)+10;
            y=y-1;
        }
        x++;
    }


}
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    int x=200,y=300,r=100;
    bresenhamCircle(x,y,r);
    circle(200,300,150);
    getch();
    closegraph();

    return 0;
}
