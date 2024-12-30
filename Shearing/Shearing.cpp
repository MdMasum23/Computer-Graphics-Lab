#include <graphics.h>
#include <iostream>
using namespace std;

void shearX(int& x, int& y, float Shx) {
    x = x + Shx * y;
}

void shearY(int& x, int& y, float Shy) {
    y = y + Shy * x;
}

void shearTriangle(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3, void (*shearFunc)(int&, int&, float), float shearFactor) {
    shearFunc(x1, y1, shearFactor);
    shearFunc(x2, y2, shearFactor);
    shearFunc(x3, y3, shearFactor);
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

    float Shx, Shy;
    int choice;
    cout << "Choose shearing direction:\n";
    cout << "1. Shear in X-direction\n";
    cout << "2. Shear in Y-direction\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter shear factor in X-direction: ";
        cin >> Shx;

        shearTriangle(x1, y1, x2, y2, x3, y3, shearX, Shx);
        setcolor(GREEN);
        line(x1, y1, x2, y2);
        line(x2, y2, x3, y3);
        line(x3, y3, x1, y1);
        outtextxy(x1 - 10, y1 - 10, "Sheared Triangle (X-Axis)");

        delay(1000);
    } else if (choice == 2) {
        cout << "Enter shear factor in Y-direction: ";
        cin >> Shy;

        shearTriangle(x1, y1, x2, y2, x3, y3, shearY, Shy);
        setcolor(RED);
        line(x1, y1, x2, y2);
        line(x2, y2, x3, y3);
        line(x3, y3, x1, y1);
        outtextxy(x1 - 10, y1 - 10, "Sheared Triangle (Y-Axis)");

        delay(1000);
    } else {
        cout << "Invalid choice!";
    }


    getch();

    closegraph();

    return 0;
}
