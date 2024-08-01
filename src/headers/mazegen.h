#ifndef MAZEGEN_H
#define MAZEGEN_H

#include "wallgrid.h"

typedef struct BacktrackData{
    bitset_t *visited;
    uint16_t max_depth;
    grid_index_t max_depth_coord;
} BacktrackData;

void mazegen_recursive_backtrack(WallGrid grid, GridCoord start);

#endif // MAZEGEN_H