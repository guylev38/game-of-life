/**
 * @file game_of_life.h
 * @author guylev38
 * @brief Module that contains the logic of the Game of Life.
 * @date 02/03/2026
 */

/*** Includes ****/

#include <sys/types.h>
#include "cell.h"

/*** Defines ***/


/*** Functions ****/

/**
 * @brief Inititalize the grid with all cells to be dead (0).
 *
 * @param grid The grid pointer to init to.
 * @return game_of_life_status_e
 */
game_of_life_status_e GAME_OF_LIFE_init_grid(cell_s **grid);

/**
 * @brief Compute the next state of the cell.
 *
 * @param cell
 * @param status
 * @return game_of_life_status_e
 */
game_of_life_status_e GAME_OF_LIFE_check_cell(cell_s *cell, u_int32_t *status);
