#include "AStar.h"
#include "Node.h"
#include <vector>

namespace AStar
{

finder::finder(Heuristic heuristic)
{
  mHeuristic = heuristic;
}

finder::~finder()
{
}

std::vector<std::vector<int>> findPath(Node startNode, Node endNode, Grid map)
{

  int startNodeRow = startNode.getRow();
  int startNodeCol = startNode.getCol();
  int endNodeRow = endNode.getRow();
  int endNodeCol = endNode.getCol();

  // 暂时用一个 vector 表示 openList，没有优先级的
  std::vector<Node> openList; // 没有指定长度
  openList.push_back(startNode);

  while (openList.size() > 0)
  {
    Node curNode = openList[openList.size() - 1];
    openList.pop_back();

    int curNodeRow = curNode.getRow();
    int curNodeCol = curNode.getCol();
    if (curNodeRow == endNodeRow && curNodeCol == endNodeCol)
    {
      // 已经到达终点
      return; // find the path
    }

    std::vector<Node> neighbors = map.getNeighbors(curNode);
    for (size_t i = 0; i < neighbors.size(); i++)
    {
      Node neighbor = neighbors[i];
      int neighborRow = neighbor.getRow();
      int neighborCol = neighbor.getCol();
      
      int new_g = 

    }
  }

  // fail to find the path
  std::vector<std::vector<int>> emptyPath;
  return emptyPath;
}

} // namespace AStar
