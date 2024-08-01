#include <stdio.h>
#include <math.h>
#include <locale.h>
#include "wallgrid.h"
#include "mazegen.h"

static unsigned short CHAR_WALL = u'█';
static char CHAR_SPACE = ' ';
static uint_fast8_t CHAR_COUNT = 2;

void print_wall()
{
    for (uint_fast8_t i = 0; i < CHAR_COUNT; i++)
    {
        printf("%lc", u'█');
    }
}

void print_space()
{
    for (uint_fast8_t i = 0; i < CHAR_COUNT; i++)
    {
        putchar(' ');
    }
}

void print_fullwall(grid_size_t count)
{
    for (grid_size_t x = 0; x < count; x++)
    {
        print_wall();
    }
    printf("%c", '\n');
}

void print_horizontal(WallGrid grid, grid_size_t y)
{
    print_wall();
    for (grid_size_t x = 0; x < grid.size.x - 1; x++)
    {
        print_space();
        if (wallgrid_state(grid, wallgrid_wall(grid, (GridCoord){x,y}, HOR)))
            print_wall();
        else
            print_space();
    }
    print_space();
    print_wall();
    printf("%c", '\n');
}

void print_vertical(WallGrid grid, grid_size_t y)
{
    print_wall();
    for (grid_size_t x = 0; x < grid.size.x; x++)
    {
        if (wallgrid_state(grid, wallgrid_wall(grid, (GridCoord){x,y}, VER)))
            print_wall();
        else
            print_space();
        print_wall();
    }
    printf("%c", '\n');
}

void print_wallgrid(WallGrid grid)
{
    print_fullwall(grid.size.x * 2 + 1);

    grid_size_t y;
    for (y = 0; y < grid.size.y - 1; y++)
    {
        print_horizontal(grid, y);
        print_vertical(grid, y);
    }
    print_horizontal(grid, y);

    print_fullwall(grid.size.x * 2 + 1);
}

int main(int, char **)
{
    WallGrid grid = wallgrid_create((GridCoord){10,20});
    mazegen_recursive_backtrack(grid, (GridCoord){0,0});

    setlocale(LC_CTYPE, "en_US.UTF-8");
    print_wallgrid(grid);

    wallgrid_destroy(grid);
    return 0;
}