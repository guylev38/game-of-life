/**
 * @name main.c
 * @author guylev38
 */

/*** Includes ***/

#include <stdio.h>
#include <time.h>
#include "raylib.h"
#include "../include/artist.h"
#include "../include/game_of_life.h"
#include "../include/dlog.h"

/*** Functions ***/

int main(void)
{
	game_of_life_status_e status = GAME_OF_LIFE_STATUS_UNINITIALIZED;

	/* Startup */
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
	SetTargetFPS(FPS);

	cell_s **curr_grid = NULL, **next_grid = NULL;
	cell_s ***h_current = &curr_grid, ***h_next = &next_grid, **tmp = NULL;
	size_t gen = 0;

	srand(time(NULL)); /* Seed the RNG */

	status = GAME_OF_LIFE_allocate_grid(h_current);
	if (GAME_OF_LIFE_STATUS_SUCCESS != status)
	{
		DLOG_ERROR("Failed to allocate h_current\n");
		goto l_cleanup;
	}

	status = GAME_OF_LIFE_allocate_grid(h_next);
	if (GAME_OF_LIFE_STATUS_SUCCESS != status)
	{
		DLOG_ERROR("Failed to allocate h_next!\n");
		goto l_cleanup;
	}

	GAME_OF_LIFE_init_grid(*h_current);

	while (true)
	{
		if (WindowShouldClose())
			goto l_cleanup;
		if (KEY_SPACE == GetKeyPressed())
			break;
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Press SPACE to start", 0, SCREEN_HEIGHT / 2, 32, RAYWHITE);
		EndDrawing();
		continue;
	}

	/* Game Loop */
	while (!WindowShouldClose())
	{
		DLOG_INFO("Generation: %d\n", gen);

		GAME_OF_LIFE_ARTIST_draw_grid(*h_current);

		GAME_OF_LIFE_calc_next_generation(*h_current, *h_next);

		/* Swap the pointers of the grids */
		tmp = *h_current;
		*h_current = *h_next;
		*h_next = tmp;

		gen++;
	}

l_cleanup:
	CloseWindow();
	GAME_OF_LIFE_free_grid(curr_grid);
	GAME_OF_LIFE_free_grid(next_grid);
	h_current = NULL;
	h_next = NULL;
	tmp = NULL;

	return (int)status;
}