#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    circle(250, 200, 50); // Draw circle with center (250, 200) and radius 50

    getch();
    closegraph();
    return 0;
}

