#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

// Function to draw polygon
void drawPolygon(int x[], int y[], int n) {
    for (int i = 0; i < n - 1; i++) {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }
    // Draw last line connecting last vertex with first vertex
    line(x[n - 1], y[n - 1], x[0], y[0]);
}

int main() {
    // Initialize graphics window
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Get number of sides of polygon from user
    int n;
    cout << "Enter the number of sides of the polygon: ";
    cin >> n;

    // Allocate arrays to store coordinates of polygon vertices
    int x[n], y[n];

    // Get mouse clicks from user to draw polygon vertices
    cout << "Click " << n << " times to draw the vertices of the polygon." << endl;
    for (int i = 0; i < n; i++) {
        int mouse_x, mouse_y;
        while (!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN, mouse_x, mouse_y);
        x[i] = mouse_x;
        y[i] = mouse_y;
        circle(x[i], y[i], 2);
    }

    // Draw polygon
    drawPolygon(x, y, n);

    // Wait for user to close graphics window
    getch();
    closegraph();
    return 0;
}

