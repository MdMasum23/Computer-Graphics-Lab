#include <graphics.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void translate(int& x, int& y, int tx, int ty) {
    x += tx;
    y += ty;
}

void scale(int& x, int& y, float Sx, float Sy) {
    x = static_cast<int>(x * Sx);
    y = static_cast<int>(y * Sy);
}

void rotate(int& x, int& y, float angle) {
    float rad = angle * M_PI / 180;
    int x_new = static_cast<int>(x * cos(rad) - y * sin(rad));
    int y_new = static_cast<int>(x * sin(rad) + y * cos(rad));
    x = x_new;
    y = y_new;
}

void drawPolygon(vector<pair<int, int>>& vertices, int color) {
    setcolor(color);
    for (size_t i = 0; i < vertices.size(); i++) {
        line(vertices[i].first, vertices[i].second,
             vertices[(i + 1) % vertices.size()].first, vertices[(i + 1) % vertices.size()].second);
    }
}

int main() {

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int n;
    cout << "Enter the number of vertices for the polygon: ";
    cin >> n;

    vector<pair<int, int>> vertices(n);
    cout << "Enter the coordinates of the vertices (x y):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i + 1 << ": ";
        cin >> vertices[i].first >> vertices[i].second;
    }

    drawPolygon(vertices, WHITE);
    outtextxy(vertices[0].first - 10, vertices[0].second - 10, "Original Polygon");

    int choice;
    cout << "\nChoose the transformation to apply:\n";
    cout << "1. Translate\n2. Scale\n3. Rotate\n";
    cin >> choice;

    if (choice == 1) {

        int tx, ty;
        cout << "Enter translation distances (tx, ty): ";
        cin >> tx >> ty;
        for (auto& vertex : vertices) {
            translate(vertex.first, vertex.second, tx, ty);
        }
        drawPolygon(vertices, GREEN);
        outtextxy(vertices[0].first - 10, vertices[0].second - 10, "Translated Polygon");
        delay(2000);
    }
    else if (choice == 2) {

        float Sx, Sy;
        cout << "Enter scaling factors (Sx, Sy): ";
        cin >> Sx >> Sy;
        for (auto& vertex : vertices) {
            scale(vertex.first, vertex.second, Sx, Sy);
        }
        drawPolygon(vertices, RED);
        outtextxy(vertices[0].first - 10, vertices[0].second - 10, "Scaled Polygon");
        delay(4000);
    }
    else if (choice == 3) {
        float angle;
        cout << "Enter rotation angle (in degrees): ";
        cin >> angle;
        for (auto& vertex : vertices) {
            rotate(vertex.first, vertex.second, angle);
        }
        drawPolygon(vertices, BLUE);
        outtextxy(vertices[0].first - 10, vertices[0].second - 10, "Rotated Polygon");
        delay(2000);
    }
    else {
        cout << "Invalid choice!";
    }

    getch();

    closegraph();

    return 0;
}
