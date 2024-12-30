#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

int x, y;

void drawStaticScenery()
{
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    circle(550, 80, 50);
    floodfill(550, 80, YELLOW);

    setcolor(WHITE);
    line(50, 350, 200, 150);
    line(200, 150, 350, 350);
    line(250, 350, 400, 200);
    line(400, 200, 550, 350);

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

void drawCloud(int x, int y)
{
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

void drawBird(int x, int y)
{
    setcolor(WHITE);
    arc(x, y, 30, 150, 20);
    arc(x + 40, y, 30, 150, 20);
}

void interactiveScenery()
{
    while (true)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            drawCloud(x, y);
        }
        if (ismouseclick(WM_RBUTTONDOWN))
        {
            getmouseclick(WM_RBUTTONDOWN, x, y);
            drawBird(x, y);
        }
        if (kbhit())
        {
            char key = getch();
            if (key == 'c' || key == 'C')
            {
                cleardevice();
                drawStaticScenery();
            }
            else if (key == 'q' || key == 'Q')
            {
                break;
            }
        }
    }
}

int main()
{
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
