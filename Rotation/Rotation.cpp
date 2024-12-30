#include <graphics.h>
#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

void rotatePoint(int& x, int& y, float angle) {
    float radians = angle * M_PI / 180.0;

    int xNew = static_cast<int>(x * cos(radians) - y * sin(radians));
    int yNew = static_cast<int>(x * sin(radians) + y * cos(radians));

    x = xNew;
    y = yNew;
}

void rotateTriangle(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3, float angle) {
    rotatePoint(x1, y1, angle);
    rotatePoint(x2, y2, angle);
    rotatePoint(x3, y3, angle);
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

    delay(1000);

    float angle;
    cout << "Enter the angle of rotation (in degrees): ";
    cin >> angle;

    rotateTriangle(x1, y1, x2, y2, x3, y3, angle);

    setcolor(GREEN);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1 - 10, y1 - 10, "Rotated Triangle");


    delay(2000);


    closegraph();

    return 0;
}
