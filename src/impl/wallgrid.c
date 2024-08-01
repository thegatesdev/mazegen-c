#include "wallgrid.h"

WallGrid wallgrid_create(GridCoord size)
{
    bitset_size_t wallCount = (size.y * (size.x - 1)) + (size.x * (size.y - 1));
    WallGrid wGrid = {
        .size = size,
        .walls = bitset_create_filled(wallCount, ~0),
    };
    return wGrid;
}

void wallgrid_destroy(WallGrid wGrid)
{
    free(wGrid.walls);
}

grid_index_t grid_move(WallGrid wGrid, grid_index_t index, GridDir direction)
{
    switch (direction)
    {
    case UP:
        return index - wGrid.size.x;
    case DOWN:
        return index + wGrid.size.x;
    case RIGHT:
        return index + 1;
    case LEFT:
        return index - 1;
    default:
        return index;
    }
}

int grid_is_edge(WallGrid wGrid, grid_index_t index)
{
    return (index + 1 % wGrid.size.x == 0) || (index + 1 % wGrid.size.y == 0);
}

grid_index_t wallgrid_grid(WallGrid wGrid, GridCoord coord)
{
    return (coord.x + coord.y * wGrid.size.x);
}

bitset_size_t wallgrid_wall(WallGrid wGrid, GridCoord coord, WallDir dir)
{
    return wallgrid_grid(wGrid, coord) * 2 - coord.y + dir;
}

bitset_size_t wallgrid_wall2(WallGrid wGrid, grid_index_t index, WallDir dir)
{
    return wallgrid_wall(wGrid, (GridCoord){index % wGrid.size.x, index / wGrid.size.x}, dir);
}

int wallgrid_valid(WallGrid wGrid, GridCoord coord, WallDir dir)
{
    return coord.x + (dir == HOR) < wGrid.size.x && coord.y + (dir == VER) < wGrid.size.y;
}

int wallgrid_valid2(WallGrid wGrid, grid_index_t index, WallDir dir)
{
    return wallgrid_valid(wGrid, (GridCoord){index % wGrid.size.x, index / wGrid.size.x}, dir);
}

WallState wallgrid_state_checked(WallGrid wGrid, GridCoord coord, WallDir dir)
{
    if (!wallgrid_valid(wGrid, coord, dir))
    {
        return OOB;
    }
    return wallgrid_state(wGrid, wallgrid_wall(wGrid, coord, dir));
}

WallState wallgrid_state(WallGrid wGrid, bitset_size_t idx)
{
    return TestBit(wGrid.walls, idx) != 0;
}

void wallgrid_clear(WallGrid wGrid, bitset_size_t idx)
{
    ClearBit(wGrid.walls, idx);
}

void wallgrid_set(WallGrid wGrid, bitset_size_t idx)
{
    SetBit(wGrid.walls, idx);
}