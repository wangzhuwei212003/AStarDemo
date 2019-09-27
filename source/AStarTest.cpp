#include <iostream>
#include <vector>
#include "AStar.h"
#include "Heuristic.h"
#include "Node.h"
#include "Grid.h"

int main(int argc, char const *argv[])
{
  AStar::finder test_finder;
  std::vector<AStar::Node *> path;
  AStar::Grid map(10, 15); // 10 * 10 的地图
  AStar::Node *pStartNode = map.getNodeAt(0, 0);
  AStar::Node *pEndNode = map.getNodeAt(9, 9);
  test_finder.findPath(pStartNode, pEndNode, map, path); // 询一条路

  return 0;
}
