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
  AStar::Node *pEndNode = map.getNodeAt(19, 19);
  test_finder.findPath(pStartNode, pEndNode, map, path); // 询一条路
  std::cout << path.size() << std::endl;
  // print path
  for (std::vector<AStar::Node *>::reverse_iterator i = path.rbegin(); i != path.rend(); i++)
  {
    std::cout << (*i)->getRow() << "," << (*i)->getCol() << std::endl;
  }
  // print path graph
  std::cout << "● is the path taken" << std::endl;
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
