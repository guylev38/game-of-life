/**
 * @file cell.h
 * @author your name
 * @brief Header file for the cell struct
 * @date 02/03/2026
 */

#ifndef __CELL_H__
#define __CELL_H__

/*** Headers ***/

#include <stdlib.h>
#include <sys/types.h>
#include "raylib.h"

/*** Structs ***/

/**
 * @brief This struct represents a cell.
 *
 */
typedef struct cell
{
    Rectangle rect;
    u_int32_t state;
} cell_s;

#endif