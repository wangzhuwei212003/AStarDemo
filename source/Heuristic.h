#pragma once

#include "Node.h"

namespace AStar
{
class Heuristic
{
private:
  /* data */
public:
  // Heuristic(/* args */);
  // ~Heuristic(); 不需要 constructor

  int manhattan(Node &nodeA, Node &nodeB) const; // 返回一个距离
  // 可扩展其他类型的距离。
};

// Heuristic::Heuristic(/* args */)
// {
// }

// Heuristic::~Heuristic()
// {
// }

} // namespace AStar
