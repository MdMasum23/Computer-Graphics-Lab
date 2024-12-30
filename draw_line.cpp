#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    line(100, 100, 300, 300);

    getch();
    closegraph();
    return 0;
}

