/**
 * @file game_of_life.c
 * @author guylev38
 * @brief Source file for the game_of_life.h header file.
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

game_of_life_status_e GAME_OF_LIFE_allocate_grid(cell_s ***grid)
{
    game_of_life_status_e ret_code = GAME_OF_LIFE_STATUS_UNINITIALIZED;

    cell_s **tmp_grid = (cell_s **)calloc(GRID_HEIGHT, sizeof(cell_s *));

    for (size_t i = 0; i < GRID_HEIGHT; i++)
        tmp_grid[i] = (cell_s *)calloc(GRID_WIDTH, sizeof(cell_s));

l_cleanup:
    ret_code = GAME_OF_LIFE_STATUS_SUCCESS;
    *grid = tmp_grid;
    tmp_grid = NULL;
    return ret_code;
}

game_of_life_status_e GAME_OF_LIFE_init_grid(cell_s **grid)
{
    game_of_life_status_e ret_code = GAME_OF_LIFE_STATUS_UNINITIALIZED;

    u_int32_t state = 0;

    for (size_t i = 0; i < GRID_HEIGHT; i++)
    {
        for (size_t j = 0; j < GRID_WIDTH; j++)
        {
            state = rand() & 1;
            grid[i][j] = (cell_s){.rect = (Rectangle){.x = j * CELL_SIZE, .y = i * CELL_SIZE, CELL_SIZE, CELL_SIZE}, .state = state};
        }
    }

l_cleanup:
    ret_code = GAME_OF_LIFE_STATUS_SUCCESS;
    return ret_code;
}

game_of_life_status_e GAME_OF_LIFE_calc_neighbours(cell_s **grid, u_int32_t x, u_int32_t y, u_int32_t *n)
{
    game_of_life_status_e ret_code = GAME_OF_LIFE_STATUS_UNINITIALIZED;
    size_t n_x = 0, n_y = 0;

    for (ssize_t i = -1; i <= 1; i++)
    {
        for (ssize_t j = -1; j <= 1; j++)
        {
            if (0 == i && 0 == j)
                continue;

            n_x = (x + j + GRID_WIDTH) % GRID_WIDTH;
            n_y = (y + i + GRID_HEIGHT) % GRID_HEIGHT;

            if (ALIVE == grid[n_y][n_x].state)
                (*n)++;
        }
    }

l_cleanup:
    ret_code = GAME_OF_LIFE_STATUS_SUCCESS;
    return ret_code;
}

game_of_life_status_e GAME_OF_LIFE_check_cell(cell_s **old_grid, cell_s **new_grid, u_int32_t x, u_int32_t y)
{
    game_of_life_status_e ret_code = GAME_OF_LIFE_STATUS_UNINITIALIZED;
    u_int32_t n = 0;

    ret_code = GAME_OF_LIFE_calc_neighbours(old_grid, x, y, &n);
    if (GAME_OF_LIFE_STATUS_SUCCESS != ret_code)
    {
        printf("calc_neighbours failed!\n");
        goto l_cleanup;
    }

    if (ALIVE == old_grid[y][x].state)
        new_grid[y][x].state = (n == 2 || n == 3);
    else
        new_grid[y][x].state = (n == 3);

    new_grid[y][x].rect = old_grid[y][x].rect;

l_cleanup:
    ret_code = GAME_OF_LIFE_STATUS_SUCCESS;
    return ret_code;
}

game_of_life_status_e GAME_OF_LIFE_calc_next_generation(cell_s **old_grid, cell_s **new_grid)
{
    game_of_life_status_e ret_code = GAME_OF_LIFE_STATUS_UNINITIALIZED;

    for (size_t i = 0; i < GRID_HEIGHT; i++)
    {
        for (size_t j = 0; j < GRID_WIDTH; j++)
        {
            ret_code = GAME_OF_LIFE_check_cell(old_grid, new_grid, j, i);
            if (GAME_OF_LIFE_STATUS_SUCCESS != ret_code)
                goto l_cleanup;
        }
    }

l_cleanup:
    ret_code = GAME_OF_LIFE_STATUS_SUCCESS;
    return ret_code;
}