#include <graphics.h>
#include <cmath>
#include <iostream>


void drawCubicBezier(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    double t;
    int prevX = x0, prevY = y0;

    for (t = 0; t <= 1; t += 0.001) {

        double xt = pow(1 - t, 3) * x0 +
                    3 * pow(1 - t, 2) * t * x1 +
                    3 * (1 - t) * t * t * x2 +
                    t * t * t * x3;

        double yt = pow(1 - t, 3) * y0 +
                    3 * pow(1 - t, 2) * t * y1 +
                    3 * (1 - t) * t * t * y2 +
                    t * t * t * y3;


        line(prevX, prevY, round(xt), round(yt));
        prevX = round(xt);
        prevY = round(yt);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);


    int x0 = 100, y0 = 400; // Starting point
    int x1 = 200, y1 = 100; // Control point 1
    int x2 = 400, y2 = 100; // Control point 2
    int x3 = 500, y3 = 400; // Ending point

    drawCubicBezier(x0, y0, x1, y1, x2, y2, x3, y3);

    getch();
    closegraph();
    return 0;
}
