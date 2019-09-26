#include "Node.h"

namespace AStar
{

Node::Node(int row, int col, bool walkable)
{
  // row = row; is this okay ?
  mRow = row;
  mCol = col;
  mWalkable = walkable;
  mG = 0;
  mF = 0;
  mH = 0;
  mOpened = false; // this means 这里表示在 openList 里，就是正在探索的点
  mClosed = false; // 这里表示，已经探索完毕的点。
}

Node::~Node() // delete node
{
  delete mParent; // free memory with delete when done.
  mParent = nullptr; // 这句话还有必要吗，我都 delete 了。
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

Node *Node::get_parent() const
{
  return mParent;
}; //
void Node::set_parent(Node &n)
{
  mParent = &n;
};

} // namespace AStar
