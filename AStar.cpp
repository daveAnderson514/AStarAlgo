#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
using std::istringstream;

void PrintGrid(std::vector<std::vector<int>> grid); // Function declaration
std::vector<std::vector<int>> ReadGridFromFile();

int main()
{
    std::vector<std::vector<int>> grid = ReadGridFromFile();
    
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

std::vector<std::vector<int>> ReadGridFromFile()
{
    std::vector<std::vector<int>> grid;
    std::ifstream myFile;
    myFile.open("1.board");
    if (myFile.is_open())
    {
        std::string line;
        
        while (getline(myFile, line))
        {
            istringstream my_stream(line);
            std::vector<int> row;
            int n;
            char c;

            while(my_stream >> n >> c)
            {
                row.push_back(n);
            }
            grid.push_back(row);
        }
    }
    return grid;
}