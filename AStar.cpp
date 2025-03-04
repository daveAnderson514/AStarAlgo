#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
using std::istringstream;

enum class State {kEmpty, kObstacle};

void PrintGrid(std::vector<std::vector<State>> grid); // Function declaration
std::vector<std::vector<State>> ReadGrid(); // Function declaration with return type

string CellString(State cell);

void PrintGrid(std::vector<std::vector<State>> grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            std::cout << CellString(grid[i][j]) << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<State>> ReadGrid()
{
    std::vector<std::vector<State>> grid;
    std::ifstream myFile;
    myFile.open("1.board");
    if (myFile.is_open())
    {
        std::string line;
        
        while (getline(myFile, line))
        {
            istringstream my_stream(line);
            std::vector<State> row;
            int n;
            char c;

            while(my_stream >> n >> c)
            {
                if (n == 0) {
                    row.push_back(State::kEmpty);
                } else {
                    row.push_back(State::kObstacle);
                }
            }
            grid.push_back(row);
        }
    }
    return grid;
}

string CellString(State cell)
{
    switch(cell)
    {
        case State::kObstacle: return "⛰️   ";
        default: return "0   ";
    }
}

int main()
{
    std::vector<std::vector<State>> grid = ReadGrid();
    
    PrintGrid(grid);

    return 0;
}