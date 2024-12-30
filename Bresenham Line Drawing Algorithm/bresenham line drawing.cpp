#include <graphics.h>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

void bresenhamLine(int x1, int y1, int x2, int y2)
{

    int dx = x2 - x1;
    int dy = y2 - y1;

    int p = 2 * dy - dx;

    int x = x1, y = y1;

    putpixel(x, y, WHITE);

    while (x < x2)
    {
        x++;

        if (p >= 0)
        {
            y++;
            p = p + 2 * (dy - dx);
        }
        else
        {
            p = p + 2 * dy;
        }

        putpixel(x, y, WHITE);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x1 = 100, y1 = 100, x2 = 300, y2 = 200;

    bresenhamLine(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

