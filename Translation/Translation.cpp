#include <graphics.h>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main() {

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x1 = 50, y1 = 200, x2 = 150, y2 = 300;

    int tx = 5;
    int ty = 0;


    while (!kbhit()) {

        cleardevice();


        rectangle(x1, y1, x2, y2);
        outtextxy(x1, y1 - 20, "Moving Rectangle");

        this_thread::sleep_for(chrono::milliseconds(50));

        x1 += tx;
        x2 += tx;
        y1 += ty;
        y2 += ty;

        if (x2 > getmaxx()) {
            x1 = 0;
            x2 = x1 + 100;
        }
    }

    closegraph();

    return 0;
}
