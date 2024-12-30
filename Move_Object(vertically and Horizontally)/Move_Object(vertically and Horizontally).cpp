#include <graphics.h>
#include <conio.h>
#include <dos.h>


void drawCar(int x, int y) {

    setcolor(YELLOW);
    rectangle(x, y, x + 50, y + 30);

    line(x + 10, y, x + 15, y - 10);
    line(x + 15, y - 10, x + 35, y - 10);
    line(x + 35, y - 10, x + 40, y);

    circle(x + 15, y + 30, 6);
    circle(x + 35, y + 30, 6);
}

void clearCar(int x, int y) {
    setcolor(BLACK);

    rectangle(x, y, x + 50, y + 30);

    line(x + 10, y, x + 15, y - 10);
    line(x + 15, y - 10, x + 35, y - 10);
    line(x + 35, y - 10, x + 40, y);

    circle(x + 15, y + 30, 6);
    circle(x + 35, y + 30, 6);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int centerX = getmaxx() / 2 - 25;
    int centerY = getmaxy() / 2 - 15;
    int x = centerX;
    int y = centerY;
    int direction = 0;

    while (!kbhit()) {
        if (direction == 0) {

            for (x = centerX; x <= centerX + 100; x += 5) {
                drawCar(x, y);
                delay(100);
                clearCar(x, y);
            }

            for (x = centerX + 100; x >= centerX; x -= 5) {
                drawCar(x, y);
                delay(100);
                clearCar(x, y);
            }

            direction = 1;
        }
        else {
            for (y = centerY; y <= centerY + 100; y += 5) {
                drawCar(x, y);
                delay(100);
                clearCar(x, y);
            }


            for (y = centerY + 100; y >= centerY; y -= 5) {
                drawCar(x, y);
                delay(100);
                clearCar(x, y);
            }

            direction = 0;
        }
    }

    closegraph();
    return 0;
}
