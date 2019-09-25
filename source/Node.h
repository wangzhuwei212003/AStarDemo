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
  // 寻路中需要用到的值
  int mG; // g
  int mF; // f
  int mH; // h
  bool mOpened;
  bool mClosed;

public:
  // Node(/* args */);
  Node(int row, int col, bool walkable);
  ~Node();

  // getters and setters
  void setWalkable(bool walkable);
  bool getWalkable() const; // const makes sure what ?

  int getRow() const;
  int getCol() const;

  int get_mG() const;
  void set_mG(int g);

  int get_mF() const;
  void set_mF(int f);

  int get_mH() const;
  void set_mH(int h);

  bool get_opened() const; // 
  void set_opened(bool v);

  bool get_closed() const; // 
  void set_closed(bool v);

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