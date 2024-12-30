#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setbkcolor(GREEN);


    setfillstyle(SOLID_FILL, BLUE);
    bar(0, 0, getmaxx(), getmaxy() / 2);

    setfillstyle(SOLID_FILL, GREEN);
    bar(0, getmaxy() / 2, getmaxx(), getmaxy());

    setfillstyle(SOLID_FILL, YELLOW);
    circle(getmaxx() / 4, getmaxy() / 4, 50);
    floodfill(getmaxx() / 4, getmaxy() / 4, WHITE);

    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, 3);
    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);

    setfillstyle(SOLID_FILL, BROWN);
    int trunkWidth = 50, trunkHeight = 100;
    int trunkX = getmaxx() / 2 - trunkWidth / 2;
    int trunkY = getmaxy() / 2;
    bar(trunkX, trunkY, trunkX + trunkWidth, trunkY + trunkHeight);

    setfillstyle(SOLID_FILL, GREEN);
    int foliageRadius = 80;
    int foliageX = getmaxx() / 2;
    int foliageY = trunkY - foliageRadius + 20;
    circle(foliageX, foliageY, foliageRadius);
    floodfill(foliageX, foliageY, WHITE);


    setfillstyle(SOLID_FILL, RED);
    int houseWidth = 100, houseHeight = 70;
    int houseX = trunkX + trunkWidth + 50;
    int houseY = trunkY + 30;
    bar(houseX, houseY, houseX + houseWidth, houseY + houseHeight);

    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    int roof[] = {houseX, houseY, houseX + houseWidth / 2, houseY - 50, houseX + houseWidth, houseY, houseX, houseY};
    fillpoly(4, roof);

    setfillstyle(SOLID_FILL, YELLOW);
    int doorWidth = 30, doorHeight = 50;
    int doorX = houseX + houseWidth / 2 - doorWidth / 2;
    int doorY = houseY + houseHeight - doorHeight;
    bar(doorX, doorY, doorX + doorWidth, houseY + houseHeight);

    setcolor(BLACK);
    int birdX = getmaxx() / 2 + 150;
    int birdY = getmaxy() / 4 - 50;
    arc(birdX - 15, birdY, 45, 135, 20);
    arc(birdX + 15, birdY, 45, 135, 20);
    setfillstyle(SOLID_FILL, BLACK);
    circle(birdX, birdY + 10, 5);
    floodfill(birdX, birdY + 10, BLACK);

    getch();
    closegraph();

    return 0;
}
