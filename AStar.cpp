#include <iostream>
#include <vector>
using namespace std;

void PrintGrid(std::vector<std::vector<int>> grid); // Function declaration

int main()
{
    std::vector<std::vector<int>> grid = 
    {{0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0}};

    PrintGrid(grid);

    return 0;
}

void PrintGrid(std::vector<std::vector<int>> grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}