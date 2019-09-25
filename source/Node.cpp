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

int Node::get_mG() const
{
  return mG;
};
void Node::set_mG(int g)
{
  mG = g;
};

int Node::get_mF() const
{
  return mF;
};
void Node::set_mF(int f)
{
  mF = f;
};

int Node::get_mH() const
{
  return mH;
};
void Node::set_mH(int h)
{
  mH = h;
};

bool Node::get_opened() const
{
  return mOpened;
}; //
void Node::set_opened(bool v)
{
  mOpened = v;
};

bool Node::get_closed() const
{
  return mClosed;
}; //
void Node::set_closed(bool v)
{
  mClosed = v;
};

} // namespace AStar