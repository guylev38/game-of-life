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
 * @brief Allocate the grid.
 *
 * @param[out] grid Pointer of the grid matrix.
 * @return game_of_life_status_e
 */
game_of_life_status_e GAME_OF_LIFE_allocate_grid(cell_s ***grid);

/**
 * @brief Initialize the grid with random values.
 *
 * @param[out] grid The matrix to initialize.
 * @return game_of_life_status_e
 */
game_of_life_status_e GAME_OF_LIFE_init_grid(cell_s **grid);

/**
 * @brief Calculates the alive neighbours of a given cell.
 *
 * @param[in] grid The current grid.
 * @param[in] x The cell's X coordinate.
 * @param[in] y The cell's Y coordinate.
 * @param[out] n Pointer to the neighbours variable.
 * @return game_of_life_status_e
 */
game_of_life_status_e GAME_OF_LIFE_calc_neighbours(cell_s **grid, u_int32_t x, u_int32_t y, u_int32_t *n);

/**
 * @brief Evaluates the next state of the cell based on the grid.
 *
 * @param[in] old_grid The current grid.
 * @param[out] new_grid The new grid.
 * @param[in] x The X coordinate of the cell.
 * @param[in] y The Y coordinate of the cell.
 * @return game_of_life_status_e
 */
game_of_life_status_e GAME_OF_LIFE_check_cell(cell_s **old_grid, cell_s **new_grid, u_int32_t x, u_int32_t y);

/**
 * @brief Calculate the next generation based on the old grid.
 *
 * @param[in] old_grid The previous generation of the grid.
 * @param[out] new_grid The new generation of the grid.
 * @return game_of_life_status_e
 */
game_of_life_status_e GAME_OF_LIFE_calc_next_generation(cell_s **old_grid, cell_s **new_grid);