/**
 * @file artist.c
 * @author guylev38
 * @brief Source file for the artist.h header file.
 * @date 03/03/2026
 */

/*** Headers ***/

#include <stdio.h>
#include "raylib.h"
#include "../include/game_of_life_s.h"
#include "../include/artist.h"
#include "../include/cell.h"

/*** Functions ***/

game_of_life_status_e GAME_OF_LIFE_ARTIST_draw_grid(cell_s **grid)
{
    game_of_life_status_e ret_code = GAME_OF_LIFE_STATUS_UNINITIALIZED;
    Rectangle *rect = NULL;

    BeginDrawing();
    ClearBackground(RAYWHITE);
    for (size_t i = 0; i < GRID_HEIGHT; i++)
    {
        for (size_t j = 0; j < GRID_WIDTH; j++)
        {
            rect = &grid[i][j].rect;
            if (ALIVE == grid[i][j].state)
                DrawRectangle(rect->x, rect->y, rect->width, rect->height, BLUE);
            else
                DrawRectangle(rect->x, rect->y, rect->width, rect->height, BLACK);

            DrawRectangleLinesEx(*rect, 1, RAYWHITE);
        }
    }
    EndDrawing();

l_cleanup:
    ret_code = GAME_OF_LIFE_STATUS_SUCCESS;
    return ret_code;
}
