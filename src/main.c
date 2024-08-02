#include <stdio.h>
#include "wallgrid.h"

int main(int, char **)
{
    WallGrid grid = wallgrid_create_filled(20, 10);

    printf("%d\n", wallgrid_is_valid(grid, wallgrid_locate(grid, 0, 0), UP));
    printf("%d\n", wallgrid_is_valid(grid, wallgrid_locate(grid, 0, 0), RIGHT));
    printf("%d\n", wallgrid_is_valid(grid, wallgrid_locate(grid, 0, 0), DOWN));
    printf("%d\n", wallgrid_is_valid(grid, wallgrid_locate(grid, 0, 0), LEFT));

    printf("%d\n", wallgrid_is_valid(grid, wallgrid_locate(grid, 19, 0), UP));
    printf("%d\n", wallgrid_is_valid(grid, wallgrid_locate(grid, 19, 0), RIGHT));
    printf("%d\n", wallgrid_is_valid(grid, wallgrid_locate(grid, 19, 0), DOWN));
    printf("%d\n", wallgrid_is_valid(grid, wallgrid_locate(grid, 19, 0), LEFT));

    printf("%d\n", wallgrid_is_valid(grid, wallgrid_locate(grid, 19, 9), UP));
    printf("%d\n", wallgrid_is_valid(grid, wallgrid_locate(grid, 19, 9), RIGHT));
    printf("%d\n", wallgrid_is_valid(grid, wallgrid_locate(grid, 19, 9), DOWN));
    printf("%d\n", wallgrid_is_valid(grid, wallgrid_locate(grid, 19, 9), LEFT));

    wallgrid_destroy(grid);
    return 0;
}