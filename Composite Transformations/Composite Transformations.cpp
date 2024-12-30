#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

void applyTransformation(float matrix[3][3], int& x, int& y) {
    float tempX = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2];
    float tempY = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2];
    x = static_cast<int>(tempX);
    y = static_cast<int>(tempY);
}

void createTranslationMatrix(float tx, float ty, float matrix[3][3]) {
    matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = tx;
    matrix[1][0] = 0; matrix[1][1] = 1; matrix[1][2] = ty;
    matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1;
}

void createScalingMatrix(float Sx, float Sy, float matrix[3][3]) {
    matrix[0][0] = Sx; matrix[0][1] = 0; matrix[0][2] = 0;
    matrix[1][0] = 0; matrix[1][1] = Sy; matrix[1][2] = 0;
    matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1;
}


void createRotationMatrix(float theta, float matrix[3][3]) {
    matrix[0][0] = cos(theta); matrix[0][1] = -sin(theta); matrix[0][2] = 0;
    matrix[1][0] = sin(theta); matrix[1][1] = cos(theta);  matrix[1][2] = 0;
    matrix[2][0] = 0;          matrix[2][1] = 0;           matrix[2][2] = 1;
}

void applyCompositeTransformation(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3, float tx, float ty, float Sx, float Sy, float theta) {

    float translation[3][3], scaling[3][3], rotation[3][3], composite[3][3];

    createTranslationMatrix(tx, ty, translation);
    createScalingMatrix(Sx, Sy, scaling);
    createRotationMatrix(theta, rotation);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            composite[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                composite[i][j] += translation[i][k] * scaling[k][j];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            translation[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                translation[i][j] += composite[i][k] * rotation[k][j];
            }
        }
    }

    applyTransformation(translation, x1, y1);
    applyTransformation(translation, x2, y2);
    applyTransformation(translation, x3, y3);
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

    float tx, ty, Sx, Sy, theta;
    cout << "Enter translation distances (tx, ty): ";
    cin >> tx >> ty;
    cout << "Enter scaling factors (Sx, Sy): ";
    cin >> Sx >> Sy;
    cout << "Enter rotation angle (in degrees): ";
    cin >> theta;
    theta = theta * 3.14159 / 180;

    applyCompositeTransformation(x1, y1, x2, y2, x3, y3, tx, ty, Sx, Sy, theta);


    setcolor(GREEN);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1 - 10, y1 - 10, "Transformed Triangle");


    getch();

    closegraph();

    return 0;
}

