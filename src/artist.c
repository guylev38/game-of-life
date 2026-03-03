/**
 * @file artist.c
 * @author guylev38
 * @brief Source file for the artist.h header file.
 * @date 03/03/2026
 */

/*** Headers ***/

#include "raylib.h"
#include "../include/game_of_life_s.h"
#include "../include/artist.h"
#include "../include/cell.h"

/*** Functions ***/

game_of_life_status_e GAME_OF_LIFE_ARTIST_draw_grid(cell_s **grid)
{
    game_of_life_status_e ret_code = GAME_OF_LIFE_STATUS_UNINITIALIZED;

    BeginDrawing();
    ClearBackground(RAYWHITE);
    for (size_t i = 0; i < SCREEN_WIDTH; i += RESOLUTION)
    {
        for (size_t j = 0; j < SCREEN_HEIGHT; j += RESOLUTION)
        {
            *rect = (Rectangle){.x = i, .y = j, .width = RESOLUTION, .height = RESOLUTION};
            DrawRectangle(rect->x, rect->y, rect->width, rect->height, BLACK);
            DrawRectangleLinesEx(*rect, 1.0, RAYWHITE);
        }
    }

    EndDrawing();
l_cleanup:
    return ret_code;
}
