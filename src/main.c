#include <stdio.h>
#include "wallgrid.h"

int main(int, char **)
{
    WallGrid grid = wallgrid_create_filled(20, 10);

    printf("%d\n", wallgrid_is_edge(grid, wallgrid_locate(grid, 0, 0)));
    printf("%d\n", wallgrid_is_edge(grid, wallgrid_locate(grid, 19, 3)));
    printf("%d\n", wallgrid_is_edge(grid, wallgrid_locate(grid, 3, 9)));
    printf("%d\n", wallgrid_is_edge(grid, wallgrid_locate(grid, 19, 9)));
    printf("%d\n", wallgrid_is_edge(grid, wallgrid_locate(grid, 3, 3)));
    printf("%d\n", wallgrid_is_edge(grid, wallgrid_locate(grid, 18, 1)));

    wallgrid_destroy(grid);
    return 0;
}