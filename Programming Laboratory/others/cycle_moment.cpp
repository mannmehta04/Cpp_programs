#include <graphics.h>
#include <cmath>

#define PI 3.14159265358979323846

int main()
{
    // Initialize graphics window
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set initial position of bicycle
    int x = getmaxx() / 4;
    int y = getmaxy() / 2;

    // Draw bicycle
    int wheel_radius = 40;
    int wheel_width = 10;
    int frame_width = 120;
    int frame_height = 30;
    int seat_height = 10;

    // Front wheel
    circle(x, y + wheel_radius + seat_height, wheel_radius);
    circle(x, y + wheel_radius + seat_height, wheel_radius / 4);
    line(x, y + seat_height, x, y + wheel_radius * 2 + seat_height);
    line(x - wheel_radius, y + wheel_radius + seat_height, x + wheel_radius, y + wheel_radius + seat_height);

    // Back wheel
    circle(x + frame_width, y + wheel_radius + seat_height, wheel_radius);
    circle(x + frame_width, y + wheel_radius + seat_height, wheel_radius / 4);
    line(x + frame_width, y + seat_height, x + frame_width, y + wheel_radius * 2 + seat_height);
    line(x + frame_width - wheel_radius, y + wheel_radius + seat_height, x + frame_width + wheel_radius, y + wheel_radius + seat_height);

    // Frame
    line(x, y + seat_height, x + frame_width, y + seat_height);
    line(x, y + seat_height, x, y - frame_height + seat_height);
    line(x + frame_width, y + seat_height, x + frame_width, y - frame_height + seat_height);
    line(x, y - frame_height + seat_height, x + frame_width, y - frame_height + seat_height);

    // Move bicycle to the right
    for (int i = 0; i < getmaxx() - x - frame_width - wheel_radius; i++) {
        cleardevice();
        x++;
        // Front wheel
        circle(x, y + wheel_radius + seat_height, wheel_radius);
        circle(x, y + wheel_radius + seat_height, wheel_radius / 4);
        line(x, y + seat_height, x, y + wheel_radius * 2 + seat_height);
        line(x - wheel_radius, y + wheel_radius + seat_height, x + wheel_radius, y + wheel_radius + seat_height);

        // Back wheel
        circle(x + frame_width, y + wheel_radius + seat_height, wheel_radius);
        circle(x + frame_width, y + wheel_radius + seat_height, wheel_radius / 4);
        line(x + frame_width, y + seat_height, x + frame_width, y + wheel_radius * 2 + seat_height);
        line(x + frame_width - wheel_radius, y + wheel_radius + seat_height, x + frame_width + wheel_radius, y + wheel_radius + seat_height);

        // Frame
        line(x, y + seat_height, x + frame_width, y + seat_height);
        line(x, y + seat_height, x, y - frame_height + seat_height);
        line(x + frame_width, y + seat_height, x + frame_width, y - frame_height + seat_height);
        line(x, y - frame_height + seat_height, x + frame_width, y - frame_height + seat_height);
        delay(10); // Add delay to slow down the animation
}

getch();
closegraph();
return 0;
}


