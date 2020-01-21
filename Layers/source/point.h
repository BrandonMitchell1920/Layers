#pragma once

#include "printing.h"

class Point
{
private:

    s8 x = TWIDTH / 2, y = HEIGHT / 2, xDir, yDir;
    u8 counter = 0;
    const std::string color;
    bool screen = true, activated;

    void flipScreen();

public:

    Point(std::string color, bool activated = false);

    void movePoint();
    void drawPoint(PrintConsole &topScreen, PrintConsole &bottomScreen);
    void toggle();
};
