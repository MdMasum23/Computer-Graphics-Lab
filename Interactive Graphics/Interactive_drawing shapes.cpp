#include<bits/stdc++.h>
#include<graphics.h>
#include<conio.h>
using namespace std;

int x, y;

void instructions()
{
    cout << "****** Welcome to Interactive Graphics ******" << endl;
    cout << "Mouse Left Click   : Draw Circle" << endl;
    cout << "Mouse Right Click  : Draw Rectangle" << endl;
    cout << "Mouse Middle Click : Draw Triangle" << endl;
    cout << "Press 'C' or 'c'   : Clear Screen" << endl;
    cout << "Press 'Esc'        : Exit the program." << endl;
}

void interactiveGraphics()
{
    while (true)
    {

        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            setcolor(WHITE);
            circle(x, y, 20);
        }

        if (ismouseclick(WM_RBUTTONDOWN))
        {
            getmouseclick(WM_RBUTTONDOWN, x, y);
            setcolor(WHITE);
            rectangle(x - 30, y - 20, x + 30, y + 20);
        }

        if (ismouseclick(WM_MBUTTONDOWN))
        {
            getmouseclick(WM_MBUTTONDOWN, x, y);
            setcolor(WHITE);
            line(x, y - 30, x - 25, y + 20);
            line(x, y - 30, x + 25, y + 20);
            line(x - 25, y + 20, x + 25, y + 20);
        }

        if (kbhit())
        {
            char key = getch();
            if (key == 27 || key == 'q' || key == 'Q')
                break;
            else if (key == 'c' || key == 'C')
            {
                cleardevice();
            }

        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    instructions();
    interactiveGraphics();

    closegraph();
    return 0;
}
