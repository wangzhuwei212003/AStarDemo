#include "Node.h"

namespace AStar
{

Node::Node()
{
  // row = row; is this okay ? this.row = row
  // mRow = row;
  // mCol = col;
  // mWalkable = walkable;
  mG = 0;
  mF = 0;
  mH = 0;
  mOpened = false; // this means 这里表示在 openList 里，就是正在探索的点
  mClosed = false; // 这里表示，已经探索完毕的点。
  mParent = nullptr;
}

Node::~Node() // delete node
{
  // delete mParent; // free memory with delete when done.
  // mParent = nullptr; // 这句话还有必要吗，我都 delete 了。
  // 同一个内存空间，这里不需要 delete //
}

void Node::setWalkable(bool walkable)
{
  mWalkable = walkable;
}

bool Node::getWalkable() const
{
  return mWalkable;
}

int Node::getRow() const
{
  return mRow;
}
void Node::set_Row(int row)
{
  mRow = row;
}
int Node::getCol() const
{
  return mCol;
}
void Node::set_Col(int col)
{
  mCol = col;
}

int Node::get_mG() const
{
  return mG;
}
void Node::set_mG(int g)
{
  mG = g;
}

int Node::get_mF() const
{
  return mF;
}
void Node::set_mF(int f)
{
  mF = f;
}

int Node::get_mH() const
{
  return mH;
}
void Node::set_mH(int h)
{
  mH = h;
}

bool Node::get_opened() const
{
  return mOpened;
} //
void Node::set_opened(bool v)
{
  mOpened = v;
}

bool Node::get_closed() const
{
  return mClosed;
} //
void Node::set_closed(bool v)
{
  mClosed = v;
}

Node *Node::get_parent() const
{
  return mParent;
}                             //
void Node::set_parent(Node *n) // &n 改为 *n
{
  mParent = n;
}

} // namespace AStar
