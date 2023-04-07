#include <graphics.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set the initial position of the cycle
    int x = 50;
    int y = getmaxy() - 100;

    // Draw the cycle
    circle(x, y, 30);
    line(x + 30, y, x + 60, y);
    line(x, y - 30, x, y - 60);
    line(x, y + 30, x, y + 60);

    // Set the direction and speed of movement
    int dx = 5;
    int dy = -5;

    // Loop infinitely to simulate movement
    while (true) {
        // Clear the previous position of the cycle
        setcolor(BLACK);
        circle(x, y, 30);
        line(x + 30, y, x + 60, y);
        line(x, y - 30, x, y - 60);
        line(x, y + 30, x, y + 60);

        // Move the cycle by the specified amount
        x += dx;
        y += dy;

        // If the cycle hits the border of the screen, reverse its direction
        if (x + 60 >= getmaxx() || x <= 0) {
            dx = -dx;
        }
        if (y + 60 >= getmaxy() || y <= 0) {
            dy = -dy;
        }

        // Draw the cycle at the new position
        setcolor(YELLOW);
        circle(x, y, 30);
        line(x + 30, y, x + 60, y);
        line(x, y - 30, x, y - 60);
        line(x, y + 30, x, y + 60);

        // Wait for some time to slow down the movement
        delay(50);
    }

    getch();
    closegraph();
    return 0;
}

