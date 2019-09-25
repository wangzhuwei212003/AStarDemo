#pragma once

namespace AStar
{
class Node
{
private:
  /* data */ // start with literal m.
  int mRow;
  int mCol;
  bool mWalkable;

public:
  // Node(/* args */);
  Node(int row, int col, bool walkable);
  ~Node();

  // getters and setters
  void setWalkable(bool walkable);
  bool getWalkable() const; // const makes sure what ?

  int getRow() const;
  int getCol() const;
};

// definition functions below. function declaration above.
// in fact, these definitions should not appear in the head file.
// Node::Node(/* args */) // constructor
// {
// }

// Node::~Node() // delete node
// {
// }

} // namespace AStar
