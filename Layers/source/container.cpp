#include "container.h"

Container::Container(PrintConsole &topScreen, PrintConsole &bottomScreen) :
    topScreen(topScreen), bottomScreen(bottomScreen) {}

void Container::drawAllPoints()
{
    for (auto& point : points)
    {
        point.drawPoint(topScreen, bottomScreen);
    }
}

void Container::update()
{
    for (auto& point : points)
    {
        point.movePoint();
    }
}

void Container::activatePoint()
{
    if (pointsActivated != numColors)
    {
        points[pointsActivated].toggle();
        pointsActivated++;
    }
}

void Container::deactivatePoint()
{
    if (pointsActivated)
    {
        points[pointsActivated - 1].toggle();
        pointsActivated--;
    }
}
