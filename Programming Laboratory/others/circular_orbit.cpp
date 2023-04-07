#include <graphics.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = getmaxx() / 2; // x-coordinate of the center of the orbit
    int yc = getmaxy() / 2; // y-coordinate of the center of the orbit
    int r = 100; // radius of the orbit
    int x, y; // coordinates of the star

    // Draw the circular orbit
    circle(xc, yc, r);

    // Move the star along the circular orbit
    for (int i = 0; ; i = (i + 5) % 360) {
        x = xc + r * cos(i * M_PI / 180);
        y = yc + r * sin(i * M_PI / 180);

        // Clear the previous position of the star
        setcolor(BLACK);
        circle(x, y, 10);

        // Draw the star at the new position
        setcolor(YELLOW);
        circle(x, y, 10);

        // Wait for some time
        delay(100);
    }

    getch();
    closegraph();
    return 0;
}

