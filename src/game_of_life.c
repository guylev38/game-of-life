/**
 * @file game_of_life.c
 * @author guylev38
 * @brief Source file for the
 * @date 03/03/2026
 /

/*** Headers ***/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "../include/cell.h"
#include "../include/game_of_life.h"
#include "../include/game_of_life_s.h"
#include "../include/artist.h"

/*** Functions ***/

game_of_life_status_e GAME_OF_LIFE_init_grid(cell_s ***grid)
{
    game_of_life_status_e ret_code = GAME_OF_LIFE_STATUS_UNINITIALIZED;

    cell_s **tmp_grid = (cell_s **)malloc(GRID_HEIGHT * sizeof(cell_s *));
    u_int32_t state = 0;

    for (size_t i = 0; i < GRID_HEIGHT; i++)
        tmp_grid[i] = (cell_s *)malloc(GRID_WIDTH * sizeof(cell_s));

    for (size_t i = 0; i < GRID_HEIGHT; i++)
    {
        for (size_t j = 0; j < GRID_WIDTH; j++)
        {
            state = rand() & 1;
            tmp_grid[i][j] = (cell_s){.rect = (Rectangle){.x = j * CELL_SIZE, .y = i * CELL_SIZE, CELL_SIZE, CELL_SIZE}, .state = state};
            printf("i: %d j:%d state: %d\n", i, j, tmp_grid[i][j].state);
        }
    }

l_cleanup:
    *grid = tmp_grid;
    tmp_grid = NULL;
    ret_code = GAME_OF_LIFE_STATUS_SUCCESS;
    return ret_code;
}

game_of_life_status_e GAME_OF_LIFE_check_cell(cell_s **grid, u_int32_t x, u_int32_t y)
{
    game_of_life_status_e ret_code = GAME_OF_LIFE_STATUS_UNINITIALIZED;

l_cleanup:
    ret_code = GAME_OF_LIFE_STATUS_SUCCESS;
    return ret_code;
}