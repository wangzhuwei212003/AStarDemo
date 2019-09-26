#include "Heuristic.h"
#include <cmath>

namespace AStar
{

int Heuristic::manhattan(Node nodeA, Node nodeB) const
{
  int rowDistance = fabs(nodeA.getRow() - nodeB.getRow()); // 不能用 abs。 error: call to 'abs' is ambiguous
  int colDistance = fabs(nodeA.getCol() - nodeB.getCol());
  return rowDistance + colDistance;
};

} // namespace AStar
