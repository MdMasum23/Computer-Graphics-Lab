#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cmath>
using namespace std;

int x, y;


void drawAndFillCubicBezier(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    int points[8000];
    int index = 0;

    double t;
    int prevX = x0, prevY = y0;
    points[index++] = x0;
    points[index++] = y0;

    for (t = 0.001; t <= 1; t += 0.001) {
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

        points[index++] = round(xt);
        points[index++] = round(yt);
    }


    points[index++] = x3;
    points[index++] = 350;
    points[index++] = x0;
    points[index++] = 350;


    setcolor(COLOR(169, 169, 169));
    setfillstyle(SOLID_FILL, COLOR(169, 169, 169));
    fillpoly(index / 2, points);
}


void drawStaticScenery() {
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    circle(550, 80, 50);
    floodfill(550, 80, YELLOW);

    drawAndFillCubicBezier(50, 350, 125, 200, 175, 200, 250, 350); // Left mountain
    drawAndFillCubicBezier(250, 350, 325, 200, 375, 200, 450, 350); // Middle mountain
    drawAndFillCubicBezier(450, 350, 525, 200, 575, 200, 640, 350); // Right mountain

    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(0, 350, 640, 480);
    floodfill(1, 351, GREEN);

    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    rectangle(80, 250, 110, 350);
    floodfill(81, 251, BROWN);

    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    circle(95, 220, 40);
    floodfill(95, 220, GREEN);

    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    rectangle(400, 250, 500, 350);
    floodfill(401, 251, RED);

    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);
    line(400, 250, 450, 200);
    line(450, 200, 500, 250);
    line(400, 250, 500, 250);
    floodfill(450, 220, BLUE);

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    rectangle(420, 270, 450, 320);
    floodfill(421, 271, WHITE);
    rectangle(460, 270, 490, 300);
    floodfill(461, 271, WHITE);
}


void drawCloud(int x, int y) {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x, y, 20);
    floodfill(x, y, WHITE);
    circle(x + 20, y, 20);
    floodfill(x + 20, y, WHITE);
    circle(x - 20, y, 20);
    floodfill(x - 20, y, WHITE);
    circle(x + 10, y - 20, 20);
    floodfill(x + 10, y - 20, WHITE);
    circle(x - 10, y - 20, 20);
    floodfill(x - 10, y - 20, WHITE);
}


void drawBird(int x, int y) {
    setcolor(WHITE);
    arc(x, y, 30, 150, 20);
    arc(x + 40, y, 30, 150, 20);
}

void interactiveScenery() {
    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            drawCloud(x, y);
        }
        if (ismouseclick(WM_RBUTTONDOWN)) {
            getmouseclick(WM_RBUTTONDOWN, x, y);
            drawBird(x, y);
        }
        if (kbhit()) {
            char key = getch();
            if (key == 'c' || key == 'C') {
                cleardevice();
                drawStaticScenery();
            } else if (key == 'q' || key == 'Q') {
                break;
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    drawStaticScenery();
    cout << "Interactive Natural Scenery" << endl;
    cout << "Instructions:" << endl;
    cout << "1. Left Click  : Draw Cloud" << endl;
    cout << "2. Right Click : Draw Bird" << endl;
    cout << "3. Press 'C'   : Clear and Redraw Scenery" << endl;
    cout << "4. Press 'Q'   : Exit Program" << endl;

    interactiveScenery();
    closegraph();
    return 0;
}
