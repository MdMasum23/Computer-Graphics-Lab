#include <graphics.h>
#include <iostream>
using namespace std;

void scaleTriangle(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3, float Sx, float Sy) {

    x1 = x1 * Sx;
    y1 = y1 * Sy;
    x2 = x2 * Sx;
    y2 = y2 * Sy;
    x3 = x3 * Sx;
    y3 = y3 * Sy;
}

int main() {

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 100;
    int x3 = 150, y3 = 50;

    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1 - 10, y1 - 10, "Original Triangle");

    float Sx, Sy;
    cout << "Enter scaling factors (Sx, Sy): ";
    cin >> Sx >> Sy;

    scaleTriangle(x1, y1, x2, y2, x3, y3, Sx, Sy);

    setcolor(GREEN);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1 - 10, y1 - 10, "Scaled Triangle");

    getch();

    closegraph();

    return 0;
}
