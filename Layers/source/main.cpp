/*
 * Name: Brandon Mitchell
 * Description: A bunch of points color the screen as they move
 *              about randomly!
 */

#include "container.h"

int main()
{
    // Seed for randomness
    srand(time(NULL));

    gfxInitDefault();

    // Bind to which screen you want, must be bound or else the system will crash
    // Four different screens to bind to: top left, top right, top, bottom
    PrintConsole topScreen, bottomScreen;

    // If no handle is needed, use NULL, else bind to handle
	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);

	// Serves as a "wrapper" for all the points
	Container container(topScreen, bottomScreen);

	u8 frameCount = 0, framesToWait = 10;

    while (aptMainLoop())
    {
        hidScanInput();

        // One of the ctrulib data types, 32 bits of memory
        u32 kDown = hidKeysDown();

        // Keys come in as binary values, bitwise and them with kDown
        // (all keys pressed) to determine if it was pressed or not
        // There also exists hidKeysHeld(), but I didn't have a use for it
        if (kDown & KEY_START) {break;}

        if      (kDown & KEY_A) {container.activatePoint();}
        else if (kDown & KEY_B) {container.deactivatePoint();}
        else if (kDown & KEY_X)
        {
            consoleSelect(&topScreen);
            drawBackground(TWIDTH, HEIGHT, CLEAR);

            consoleSelect(&bottomScreen);
            drawBackground(BWIDTH, HEIGHT, CLEAR);
        }

        // Draws too quickly with out, only draws every number of frames
        if (frameCount == framesToWait)
        {
            container.update();
            container.drawAllPoints();

            frameCount = 0;
        }

        frameCount++;

        gfxFlushBuffers();
        gfxSwapBuffers();

        // 3DS works at 60 frames per second, must wait before trying
        // to draw again or things look ugly and messed up.
        gspWaitForVBlank();
    }
	gfxExit();
	return 0;
}
