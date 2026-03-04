/**
 * @file drawer.h
 * @author guylev38
 * @brief Module for drawing the grid.
 * @date 02/03/2026
 */

#ifndef __ARTIST_H__
#define __ARITST_H__

/*** Includes ***/

#include <sys/types.h>

#include "game_of_life_s.h"
#include "cell.h"

/*** Defines ***/
#define SCREEN_WIDTH (600)
#define SCREEN_HEIGHT (600)
#define WINDOW_TITLE ("Game of Life")
#define FPS (60)
#define CELL_SIZE (30)
#define GRID_WIDTH (SCREEN_WIDTH / CELL_SIZE)
#define GRID_HEIGHT (SCREEN_HEIGHT / CELL_SIZE)

/*** Functions ***/

/**
 * @brief Draws the grid from a 2D array of Cell structs.
 *
 * @param[in] grid 2D array of Cell structs representing the grid.
 * @return game_of_life_status_e
 */
game_of_life_status_e GAME_OF_LIFE_ARTIST_draw_grid(cell_s **grid);

#endif