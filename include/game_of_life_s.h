/**
 * @file game_of_life_s.h
 * @author t_guyle
 * @brief Status enum for the project.
 * @date 02/03/2026
 */

#ifndef __GAME_OF_LIFE_S__
#define __GAME_OF_LIFE_S__

/*** Enums ***/
typedef enum game_of_life_status_e
{
    GAME_OF_LIFE_STATUS_UNINITIALIZED = -1,

    GAME_OF_LIFE_STATUS_SUCCESS = 0,
    GAME_OF_LIFE_STATUS_GAME_OF_LIFE_ALLOCATE_GRID_TMP_GRID_CALLOC_FAILED,
    GAME_OF_LIFE_STATUS_GAME_OF_LIFE_ALLOCATE_GRID_TMP_GRID_INNER_CALLOC_FAILED
} game_of_life_status_e;

#endif