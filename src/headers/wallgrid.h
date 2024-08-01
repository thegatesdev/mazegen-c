#ifndef WALLGRID_H
#define WALLGRID_H

#include <stdint.h>
#include "bitset.h"

typedef uint8_t grid_size_t;
typedef uint16_t grid_index_t;

typedef struct GridCoord
{
    grid_size_t x;
    grid_size_t y;
} GridCoord;

typedef enum GridDir{
    NONE, UP, RIGHT, LEFT, DOWN
} GridDir;

// Cannot be const
// setting a bit at the 0th index in the array causes segfault
// because array pointer points to that element//
typedef struct WallGrid
{
    GridCoord size;
    bitset_t *walls;
} WallGrid;

typedef enum WallDir
{
    VER = 0,
    HOR = 1
} WallDir;

typedef enum WallState
{
    EMPTY = 0,
    WALL = 1,
    OOB = 2
} WallState;

WallGrid wallgrid_create(GridCoord size);

void wallgrid_destroy(WallGrid wGrid);

grid_index_t grid_move(WallGrid wGrid, grid_index_t index, GridDir direction);

int grid_is_edge(WallGrid wGrid, grid_index_t index);

grid_index_t wallgrid_grid(WallGrid wGrid, GridCoord pos);

bitset_size_t wallgrid_wall(WallGrid wGrid, GridCoord pos, WallDir dir);

bitset_size_t wallgrid_wall2(WallGrid wGrid, grid_index_t index, WallDir dir);

int wallgrid_valid(WallGrid wGrid, GridCoord pos, WallDir dir);

int wallgrid_valid2(WallGrid wGrid, grid_index_t index, WallDir dir);

WallState wallgrid_state_checked(WallGrid wGrid, GridCoord pos, WallDir dir);

WallState wallgrid_state(WallGrid wGrid, bitset_size_t idx);

void wallgrid_clear(WallGrid wGrid, bitset_size_t idx);

void wallgrid_set(WallGrid wGrid, bitset_size_t idx);

#endif // WALLGRID_H
