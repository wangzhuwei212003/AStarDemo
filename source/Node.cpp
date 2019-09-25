#include "Node.h"

namespace AStar
{

Node::Node(int row, int col, bool walkable)
{
  // row = row; is this okay ?
  mRow = row;
  mCol = col;
  mWalkable = walkable;
}

Node::~Node() // delete node
{
}

void Node::setWalkable(bool walkable)
{
  mWalkable = walkable;
};

bool Node::getWalkable() const
{
  return mWalkable;
};

int Node::getRow() const
{
  return mRow;
};
int Node::getCol() const
{
  return mCol;
};

} // namespace AStar
