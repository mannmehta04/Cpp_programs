#include <graphics.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

#define PI 3.14159265358979323846

// Function to draw a pie slice
void drawPieSlice(int x, int y, int radius, int startAngle, int endAngle, color_t color) {
    setcolor(color);
    int midAngle = (startAngle + endAngle) / 2;
    int midX = x + (radius / 2) * cos(midAngle * PI / 180);
    int midY = y + (radius / 2) * sin(midAngle * PI / 180);
    setfillstyle(SOLID_FILL, color);
    pieslice(x, y, startAngle, endAngle, radius);
    outtextxy(midX, midY, to_string(endAngle - startAngle).c_str());
}

// Function to draw a bar
void drawBar(int x, int y, int width, int height, color_t color) {
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    bar(x, y, x + width, y + height);
}

int main() {
    // Initialize graphics window
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set position and size of charts
    int pieChartX = 150;
    int pieChartY = 150;
    int pieChartRadius = 100;
    int barChartX = 450;
    int barChartY = 100;
    int barChartWidth = 300;
    int barChartHeight = 300;

    // Read sales data from file
    ifstream inFile("sales.txt");
    int sales[12];
    int totalSales = 0;
    for (int i = 0; i < 12; i++) {
        string monthName;
        int salesAmount;
        inFile >> monthName >> salesAmount;
        sales[i] = salesAmount;
        totalSales += salesAmount;
    }
    inFile.close();

    // Draw pie chart
    int currentAngle = 0;
    for (int i = 0; i < 12; i++) {
        int sliceAngle = round((double)sales[i] / totalSales * 360);
        drawPieSlice(pieChartX, pieChartY, pieChartRadius, currentAngle, currentAngle + sliceAngle, i + 1);
        currentAngle += sliceAngle;
    }

    // Draw bar chart
    int barX = barChartX + 20;
    int barY = barChartY + 20;
    int maxSales = *max_element(sales, sales + 12);
    for (int i = 0; i < 12; i++) {
        int barHeight = round((double)sales[i] / maxSales * barChartHeight);
        drawBar(barX, barY, barChartWidth / 12 - 10, barHeight, i + 1);
        barX += barChartWidth / 12;
    }

    // Wait for user to close graphics window
    getch();
    closegraph();

    return 0;
}

