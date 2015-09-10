#ifndef _CLOSEDLIST_H_
#define _CLOSEDLIST_H_

#include <vector>
#include <set>
#include <string>

namespace ai
{
  namespace Search
  {
    /**
     * Class to store Nodes that have already
     * been found during graph search.
     */
    class ClosedList
    {
    public:

      ClosedList();

      void Clear();
      bool Contains(const Node * const node_in) const;
      bool Insert(Node * node_in);
      size_t Size() const;

    protected:
      void SetStyle(const Node * const node_in);
      enum { US_UNKNOWN, US_NO, US_YES };
      int use_set;
      std::vector<Node *> closed_list;
      std::set<std::string> closed_set;
    private:
    };

  }
}
#endif /* _CLOSEDLIST_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
