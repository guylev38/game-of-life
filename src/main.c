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
	game_of_life_status_e status = GAME_OF_LIFE_STATUS_UNINITIALIZED;

	// Startup
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
	SetTargetFPS(FPS);

	cell_s **old_grid, **curr_grid = NULL;

	status = GAME_OF_LIFE_init_grid(&curr_grid);
	if (GAME_OF_LIFE_STATUS_SUCCESS != status)
	{
		printf("init_grid failed\n");
		goto l_cleanup;
	}

	// Game Loop
	while (!WindowShouldClose())
	{
		old_grid = curr_grid;

		/*
			eval(old_grid) for all in grid
			modify(curr_grid)
		*/

		status = GAME_OF_LIFE_ARTIST_draw_grid(curr_grid);
		if (GAME_OF_LIFE_STATUS_SUCCESS != status)
		{
			printf("Crashed!\n");
			goto l_cleanup;
		}
	}

	// Cleanup

l_cleanup:
	CloseWindow();

	return (int)status;
}
