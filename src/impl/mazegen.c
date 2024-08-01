#include "mazegen.h"

GridDir random_unvisited(WallGrid grid, bitset_t *visited, grid_index_t index)
{
    grid_index_t up = grid_move(grid, index, UP);
    grid_index_t right = grid_move(grid, index, RIGHT);
    grid_index_t down = grid_move(grid, index, DOWN);
    grid_index_t left = grid_move(grid, index, LEFT);

    if (wallgrid_valid2(grid, up, VER) && !TestBit(visited, up))
        return UP;
    if (wallgrid_valid2(grid, index, HOR) && !TestBit(visited, right))
        return RIGHT;
    if (wallgrid_valid2(grid, index, VER) && !TestBit(visited, down))
        return DOWN;
    if (wallgrid_valid2(grid, left, HOR) && !TestBit(visited, left))
        return LEFT;
    return NONE;
}

void backtrack(WallGrid grid, BacktrackData *data, uint16_t depth, grid_index_t index)
{
    SetBit(data->visited, index);
    if (grid_is_edge(grid, index) && depth > data->max_depth)
    {
        data->max_depth = depth;
        data->max_depth_coord = index;
    }

    GridDir dir = random_unvisited(grid, data->visited, index);

    bitset_size_t bitIdx;
    switch (dir)
    {
    case UP:
        bitIdx = wallgrid_wall2(grid, grid_move(grid, index, UP), VER);
        break;
    case DOWN:
        bitIdx = wallgrid_wall2(grid, index, VER);
        break;
    case LEFT:
        bitIdx = wallgrid_wall2(grid, grid_move(grid, index, LEFT), HOR);
        break;
    case RIGHT:
        bitIdx = wallgrid_wall2(grid, index, HOR);
        break;
    default:
        return;
    }

    wallgrid_clear(grid, bitIdx);
    backtrack(grid, data, depth + 1, grid_move(grid, index, dir));
}

void mazegen_recursive_backtrack(WallGrid grid, GridCoord start)
{
    BacktrackData *data = malloc(sizeof *data);
    data->visited = bitset_create(grid.size.x * grid.size.y);
    data->max_depth = 0;
    data->max_depth_coord = 0;
    backtrack(grid, data, 0, wallgrid_grid(grid, start));
}
