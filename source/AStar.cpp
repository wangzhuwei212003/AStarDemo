#include "AStar.h"
#include "Node.h"
#include <vector>
#include <algorithm>

namespace AStar
{

finder::finder()
{
}

finder::~finder()
{
}

int finder::findPath(Node *starNode, Node *endNode, Grid &map, std::vector<Node *> &path)
{

  // 暂时用一个 vector 表示 openList，没有优先级的
  std::vector<Node *> openList; // 没有指定长度
  // std::vector<Node>::iterator it; // 这个是用来查找 openList 里的元素。find 方法需要改。

  openList.push_back(starNode);

  while (openList.size() > 0)
  {
    Node *curNode = openList[openList.size() - 1];
    openList.pop_back();

    int curNodeRow = curNode->getRow();
    int curNodeCol = curNode->getCol();
    if (curNodeRow == endNode->getRow() && curNodeCol == endNode->getCol())
    {
      // 已经到达终点
      // return; // find the path
      //std::vector<Node> emptyPath;
      //return emptyPath;
      // TODO: generate path into path
      path.clear();
      Node* NodeTmp=curNode;
      do
      {
        path.push_back(NodeTmp);
        NodeTmp = NodeTmp->get_parent();
      } while (NodeTmp->getRow() != starNode->getRow() || NodeTmp->getCol() != starNode->getCol());
      path.push_back(NodeTmp);
      return 0;
    }

    int cur_g = curNode->get_mG(); // 得到当前 node 的已走过路程的花费。

    std::vector<Node *> neighbors;
    map.getNeighbors(curNode, neighbors);
    for (size_t i = 0; i < neighbors.size(); i++)
    {
      Node *neighbor = neighbors[i];
      int neighborRow = neighbor->getRow();
      int neighborCol = neighbor->getCol();

      int neighbor_newG = cur_g + 1;
      int neighbor_g = neighbor->get_mG();

      bool neighbor_opened = neighbor->get_opened();
      bool neighbor_closed = neighbor->get_closed();

      if (!neighbor_opened || neighbor_newG < neighbor_g)
      {
        neighbor->set_mG(neighbor_newG);
        neighbor->set_mH(mHeuristic.manhattan(*neighbor, *map.getNodeAt(endNode->getRow(), endNode->getCol()))); // 计算到终点的 Manhattan 距离
        neighbor->set_mF(neighbor->get_mG() + neighbor->get_mH());                                               // f = g + h
        // neighbor.set_parent(&curNode); 这么写不行，initial value of reference to non-const must be an lvalue
        neighbor->set_parent(curNode); // reference 的时候就直接传对象。// 需要分清楚是同一个对象还是拷贝的新的不同对象。

        if (!neighbor_opened)
        {
          openList.push_back(neighbor);
          neighbor->set_opened(true);
        }
        else
        { // 这里是需要更新 g 的 neighbor。
          // the neighbor can be reached with smaller cost.
          // Since its f value has been updated, we have to
          // update its position in the open list
          // openList.updateItem(neighbor);

          // 找到 neighbor 并改变 neighbor 里的数据。上面是指针的话，就已经改变了。
        }
      }
    }
  }

  // fail to find the path
  path.clear();
}

} // namespace AStar
