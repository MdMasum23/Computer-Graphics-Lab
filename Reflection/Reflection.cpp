#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

void reflectRight(float x, float y, float pivot_x, float &x_new, float &y_new) {
    x_new = 2 * pivot_x - x;
    y_new = y;
}

void drawCircle(float centerX, float centerY, int radius) {
    circle(centerX, centerY, radius);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    float centerX = 200, centerY = 200;
    int radius = 50;

    float pivot_x = centerX + radius;

    setcolor(WHITE);
    drawCircle(centerX, centerY, radius);
    outtextxy(250, 50, (char*)"Original Circle");

    float centerX_new, centerY_new;
    reflectRight(centerX, centerY, pivot_x, centerX_new, centerY_new);

    setcolor(RED);
    drawCircle(centerX_new, centerY_new, radius);
    outtextxy(250, 80, (char*)"Reflected Circle");

    setcolor(GREEN);
    line(pivot_x, 0, pivot_x, getmaxy());
    outtextxy(pivot_x + 10, 10, (char*)"Pivot Line");

    getch();
    closegraph();
    return 0;
}
