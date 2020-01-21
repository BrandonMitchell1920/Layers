#include "point.h"

void Point::flipScreen()
{
    u8 width = screen ? TWIDTH : BWIDTH;

    if      (x == width)  {x -= width;}
    else if (x < 0)       {x += width;}

    else if (y == HEIGHT)  // This is the difficult part
    {
        if (screen)
        {
            if (!(x < 5 || x > 44))  // Edges of top screen
            {
                x -= 5;
                screen = !screen;
            }
        }
        else
        {
            x += 5;
            screen = !screen;
        }
        y -= HEIGHT;
    }

    else if (y < 0)
    {
        if (screen)
        {
            if (!(x < 5 || x > 44))  // Edges of top screen
            {
                x -= 5;
                screen = !screen;
            }
        }
        else
        {
            x += 5;
            screen = !screen;
        }
        y += HEIGHT;
    }
}

Point::Point(std::string color, bool activated) :
    color(color), activated(activated) {}

void Point::movePoint()
{
    if (activated)  // Point is activated, else it won't move
    {
        if (!counter)  // Counter is zero
        {
            counter = getRand(10) + 3;  // getRand will return 0 - 9, so I add three to prevent 0 movement

            switch (getRand(4))  // Movement direction is changed
            {
                case 0: xDir =  0; yDir = -1; break;
                case 1: xDir =  0; yDir =  1; break;
                case 2: xDir = -1; yDir =  0; break;
                case 3: xDir =  1; yDir =  0; break;
            }
        }
        x += xDir; y += yDir;

        Point::flipScreen();  // Check if x, y in bounds of screen

        counter--;
    }
}

void Point::drawPoint(PrintConsole &topScreen, PrintConsole &bottomScreen)
{
    if (activated)  // Won't draw if not activated
    {
        consoleSelect(screen ? &topScreen : &bottomScreen);
        printToConsole(x, y, color);
    }
}

void Point::toggle()
{
    activated = !activated;
}
