#include <graphics.h>
#include <dos.h>

void drawScene(int sunX, int carX) {

    cleardevice();

    setfillstyle(SOLID_FILL, BLUE);
    bar(0, 0, getmaxx(), getmaxy() / 2);


    setfillstyle(SOLID_FILL, GREEN);
    bar(0, getmaxy() / 2, getmaxx(), getmaxy());


    setfillstyle(SOLID_FILL, YELLOW);
    circle(sunX, getmaxy() / 4, 50);
    floodfill(sunX, getmaxy() / 4, WHITE);

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

    setfillstyle(SOLID_FILL, DARKGRAY);
    int roadHeight = 60;
    bar(0, getmaxy() - roadHeight, getmaxx(), getmaxy());

    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, 2);
    for(int x = 0; x < getmaxx(); x += 80) {
        line(x, getmaxy() - roadHeight/2, x + 40, getmaxy() - roadHeight/2);
    }

    setfillstyle(SOLID_FILL, RED);
    int carY = getmaxy() - roadHeight + 10;
    int carHeight = 30;
    int carWidth = 60;

    bar(carX, carY, carX + carWidth, carY + carHeight);

    setfillstyle(SOLID_FILL, RED);
    int carRoof[] = {
        carX + 10, carY,
        carX + 20, carY - 20,
        carX + carWidth - 20, carY - 20,
        carX + carWidth - 10, carY
    };
    fillpoly(4, carRoof);

    setfillstyle(SOLID_FILL, BLACK);
    circle(carX + 15, carY + carHeight, 8);
    floodfill(carX + 15, carY + carHeight, WHITE);
    circle(carX + carWidth - 15, carY + carHeight, 8);
    floodfill(carX + carWidth - 15, carY + carHeight, WHITE);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int carX = -60;
    int sunX = getmaxx() / 4;
    int sunDirection = -1;

    while(carX <= getmaxx()) {
        drawScene(sunX, carX);
        delay(50);

        carX += 5;
        sunX += (3 * sunDirection);

        if(sunX <= 50) {
            sunX = getmaxx() - 50;
        }
        if(sunX >= getmaxx() - 50) {
            sunX = 50;
        }
    }

    getch();
    closegraph();
    return 0;
}
