#include "Grid.h"
#include "Node.h"
#include <vector>

namespace AStar
{
Grid::Grid(int totalRow, int totalCol)
{
  // 初始化 mNodes
  mTotalRow = totalRow;
  mTotalCol = totalCol;

  std::vector<std::vector<Node>> _nodes(
      totalRow,
      std::vector<Node>(totalCol));

  for (size_t i = 0; i < totalRow; i++)
  {
    for (size_t j = 0; j < totalCol; j++)
    {
      _nodes[i][j] = Node(i, j, false);
    }
  }

  // mNodes = _nodes; // 这么直接赋值能吗？
  mNodes = new Node[totalRow * totalCol]; // 这么直接赋值能吗？

}

Grid::~Grid()
{
}

Node Grid::getNodeAt(int row, int col) const
{
  return mNodes[row][col];
};

bool Grid::isWalkableAt(int row, int col) const
{
  return isInside(row, col) && mNodes[row][col].getWalkable();
};

bool Grid::isInside(int row, int col) const
{
  return (col >= 0 && col < mTotalCol) && (row >= 0 && row < mTotalRow);
};

void Grid::setWalkableAt(int row, int col, bool walkable)
{
  Node tmp = getNodeAt(row, col);
  tmp.setWalkable(walkable);
};

std::vector<Node> Grid::getNeighbors(Node curNode) const
{

  int row = curNode.getRow();
  int col = curNode.getCol();
  std::vector<Node> neighbors; // 这样初始化没有指定长度有什么问题
  // vector,
  // push_back, push from the back,
  // pop_back, pop from the back
  // insert, insert at specified position
  // specific 明确的 具体的
  // specified 指定的

  //仅考虑 上下左右 四个方向
  // ↑
  if (isWalkableAt(row - 1, col))
  {
    neighbors.push_back(getNodeAt(row - 1, col));
  }
  // →
  if (isWalkableAt(row, col + 1))
  {
    neighbors.push_back(getNodeAt(row, col + 1));
  }
  // ↓
  if (isWalkableAt(row + 1, col))
  {
    neighbors.push_back(getNodeAt(row + 1, col));
  }
  // ←
  if (isWalkableAt(row, col - 1))
  {
    neighbors.push_back(getNodeAt(row, col - 1));
  }

  return neighbors;
};

} // namespace AStar
