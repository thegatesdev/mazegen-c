#include "wallgrid.h"

#define WallGridSize(w,h) ((w + 1) * (h + 1))

WallGrid wallgrid_create_filled(wallgrid_size width, wallgrid_size height)
{
    WallGrid grid = {
        .width = width,
        .height = height,
        .walls = bitset_create_filled(WallGridSize(width, height), ~0),
    };
    return grid;
}

void wallgrid_destroy(WallGrid wGrid)
{
    bitset_destroy(wGrid.walls);
}

inline wallgrid_index wallgrid_locate(WallGrid grid, wallgrid_size x, wallgrid_size y)
{
    return x + y * grid.width;
}

int wallgrid_is_edge(WallGrid grid, wallgrid_index index)
{
    return 0;
}

int wallgrid_is_valid(WallGrid grid, wallgrid_index index, WallDir dir)
{
    switch (dir)
    {
    case UP:
        return index >= grid.width;
    case RIGHT:
        return (index % grid.width) + 1 < grid.width;
    case DOWN:
        return index < grid.width * (grid.height - 1);
        /*
        Possible optimization from (index / grid.width) + 1 < grid.height
        if dividing is more expensive.
        */
    case LEFT:
        return (index % grid.width) > 0;
    }
}

WallState wallgrid_state(WallGrid grid, wallgrid_index index, WallDir dir)
{
    return 0;
}

wallgrid_index wallgrid_move(WallGrid grid, wallgrid_index index, WallDir dir)
{
    return 0;
}

void wallgrid_break(WallGrid grid, wallgrid_index index, WallDir dir)
{
}

void wallgrid_place(WallGrid grid, wallgrid_index index, WallDir dir)
{
}