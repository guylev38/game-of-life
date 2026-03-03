/**
 * @name main.c
 * @author guylev38
 */

/*** Includes ***/

#include <stdio.h>
#include "raylib.h"
#include "../include/artist.h"
#include "../include/game_of_life.h"

/*** Functions ***/

int main(void)
{
	// Startup
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
	SetTargetFPS(FPS);

	Rectangle *rect = malloc(sizeof(Rectangle));

	// Game Loop
	while (!WindowShouldClose())
	{
	}

	// Cleanup

l_cleanup:
	CloseWindow();
	free(rect);

	return 0;
}
