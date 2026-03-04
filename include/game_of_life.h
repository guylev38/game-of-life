/**
 * @file game_of_life.h
 * @author guylev38
 * @brief Module that contains the logic of the Game of Life.
 * @date 02/03/2026
 */

/*** Includes ****/

#include <sys/types.h>
#include "cell.h"
#include "game_of_life_s.h"

/*** Functions ****/

/**
 * @brief Inititalize the grid with all cells to be dead (0).
 *
 * @param[out] grid Pointer of the grid matrix.
 * @return game_of_life_status_e
 */
game_of_life_status_e GAME_OF_LIFE_init_grid(cell_s ***grid);

/**
 * @brief Evaluates the next state of the cell based on the grid.
 *
 * @param[in, out] grid The grid matrix.
 * @param[in] x The X coordinate of the cell.
 * @param[in] y The Y coordinate of the cell.
 * @return game_of_life_status_e
 */
game_of_life_status_e GAME_OF_LIFE_check_cell(cell_s **grid, u_int32_t x, u_int32_t y);

/**
 * @brief Calculate the next generation of
 *
 * @param[in] old_grid The previous generation of the grid.
 * @param[out] new_grid The new generation of the grid.
 * @return game_of_life_status_e
 */
game_of_life_status_e GAME_OF_LIFE_calc_next_generation(cell_s **old_grid, cell_s **new_grid);