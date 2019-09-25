#include "Heuristic.h"
#include <cmath>

namespace AStar
{

int Heuristic::manhattan(Node nodeA, Node nodeB) const
{
  int rowDistance = abs(nodeA.getRow() - nodeB.getRow());
  int colDistance = abs(nodeA.getCol() - nodeB.getCol());
  return rowDistance + colDistance;
};

} // namespace AStar
