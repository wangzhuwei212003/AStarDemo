#include <iostream>
#include <vector>
#include "AStar.h"
#include "Heuristic.h"
#include "Node.h"
#include "Grid.h"

int main(int argc, char const *argv[])
{
  AStar::finder test_finder;
  // AStar::Node start = AStar::Node(0, 0, true);
  // AStar::Node end = AStar::Node(9, 9, true);
  AStar::Grid map = AStar::Grid(10, 10);                                // 10 * 10 的地图
  std::vector<AStar::Node> res = test_finder.findPath(0, 0, 9, 9, map); // 询一条路

  return 0;
}
