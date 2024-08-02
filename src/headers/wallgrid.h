#ifndef WALLGRID_H
#define WALLGRID_H

#include <stdint.h>
#include "bitset.h"

typedef unsigned int wallgrid_size;
typedef uint_fast32_t wallgrid_index;

typedef struct WallGrid
{
    wallgrid_size width;
    wallgrid_size height;
    Bitset *walls;
} WallGrid;

typedef enum WallDir{
    UP, RIGHT, DOWN, LEFT
} WallDir;

typedef enum WallState{
    EMPTY, WALL, OOB
} WallState;

WallGrid wallgrid_create_filled(wallgrid_size width, wallgrid_size height);

void wallgrid_destroy(WallGrid grid);

wallgrid_index wallgrid_locate(WallGrid grid, wallgrid_size x, wallgrid_size y);

int wallgrid_is_edge(WallGrid grid, wallgrid_index index);

int wallgrid_is_valid(WallGrid grid, wallgrid_index index, WallDir dir);

void wallgrid_break(WallGrid grid, wallgrid_index index, WallDir dir);

WallState wallgrid_state(WallGrid grid, wallgrid_index index, WallDir dir);

wallgrid_index wallgrid_move(WallGrid grid, wallgrid_index index, WallDir dir);

void wallgrid_break(WallGrid grid, wallgrid_index index, WallDir dir);

void wallgrid_place(WallGrid grid, wallgrid_index index, WallDir dir);

#endif // WALLGRID_H