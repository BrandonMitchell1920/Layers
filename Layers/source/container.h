#pragma once

#include "point.h"

class Container
{
private:

    static const u8 numColors = 6;

    Point points[numColors] = {Point(RED, true),
                               Point(GREEN),
                               Point(YELLOW),
                               Point(BLUE),
                               Point(MAGENTA),
                               Point(CYAN)};

    u8 pointsActivated = 1;

    PrintConsole topScreen, bottomScreen;

public:

    Container(PrintConsole &topScreen, PrintConsole &bottomScreen);

    void drawAllPoints();
    void update();
    void activatePoint();
    void deactivatePoint();
};
