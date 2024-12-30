#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int triangle[] = {150, 300, 250, 150, 350, 300, 150, 300};
    drawpoly(4, triangle);

    getch();
    closegraph();
    return 0;
}

