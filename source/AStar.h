#pragma once
#include <vector>
#include "Heuristic.h"
#include "Node.h"
#include "Grid.h"

namespace AStar
{
class finder
{
private:
  /* data */
  Heuristic mHeuristic;

public:
  finder();
  ~finder();

  int findPath(Node *starNode, Node *endNode, Grid &map, std::vector<Node *> &path);
  // 找路径，返回一段路径，二维数组。int
};

// finder::finder(/* args */)
// {
// }

// finder::~finder()
// {
// }

} // namespace AStar
