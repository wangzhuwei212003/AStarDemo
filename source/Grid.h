#pragma once
#include <vector>
#include "Node.h"

namespace AStar
{
class Grid
{
private:
  /* data */
  int mTotalRow;
  int mTotalCol;
  // std::vector<Node[]> mNodes; 不是这么写的
  // std::vector<std::vector<Node>> mNodes;
  // 元素是 Node 对象的二维数组，vector 可变长度的数组
  // 三维数组怎么表示？？

  Node **mNodes;

public:
  Grid(int totalRow, int totalCol);
  ~Grid();

  Node &getNodeAt(int row, int col) const;
  bool isWalkableAt(int row, int col) const;
  bool isInside(int row, int col) const;
  void setWalkableAt(int row, int col, bool walkable);
  std::vector<Node> getNeighbors(Node curNode) const;
  // 根据一个 node 找到附近的能够行走的 node
};

// Grid::Grid(/* args */)
// {
// }

// Grid::~Grid()
// {
// }

} // namespace AStar
