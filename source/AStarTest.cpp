#include <iostream>
#include <vector>
#include "AStar.h"
#include "Heuristic.h"
#include "Node.h"
#include "Grid.h"

#define ROW 20
#define COL 20

int main(int argc, char const *argv[])
{
  AStar::finder test_finder;
  std::vector<AStar::Node *> path;
  AStar::Grid map(ROW, COL); // 10 * 10 的地图
  AStar::Node *pStartNode = map.getNodeAt(0, 0);
  int endRow = ROW - 1;
  int endCol = COL - 1;

  std::cout << "This test will search a path that start at (0,0) point. \n"
            << "The map size is " << ROW << "x" << COL << ".\n"
            << "Choose an end point. \n"
            << "Row(0-" << ROW - 1 << "): ";
  std::cin >> endRow;
  std::cout << "Col(0-" << COL - 1 << "): ";
  std::cin >> endCol;
  std::cout << "End Point is " << endRow << ", " << endCol << ".\n";

  AStar::Node *pEndNode = map.getNodeAt(endRow, endCol);
  test_finder.findPath(pStartNode, pEndNode, map, path); // 询一条路
  std::cout << "Total length of the path is "
            << path.size() << ".\n"
            << std::endl;
  // print path
  for (std::vector<AStar::Node *>::reverse_iterator i = path.rbegin(); i != path.rend(); i++)
  {
    std::cout << "Row " << (*i)->getRow()
              << ", Col " << (*i)->getCol()
              << std::endl;
  }
  // print path graph
  std::cout << "\n● is the path taken.\n"
            << std::endl;
  for (size_t i = 0; i < ROW; i++)
  {
    for (size_t j = 0; j < COL; j++)
    {
      bool found = false;
      for (std::vector<AStar::Node *>::reverse_iterator it = path.rbegin(); it != path.rend(); it++)
      {
        if ((*it)->getRow() == i && (*it)->getCol() == j)
        {
          found = true;
        }
      }
      if (found)
      {
        std::cout << "●";
      }
      else
      {
        std::cout << "□";
      }
    }
    std::cout << std::endl;
  }
  return 0;
}
