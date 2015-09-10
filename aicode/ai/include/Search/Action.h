#ifndef _SEARCH_ACTION_H_
#define _SEARCH_ACTION_H_
namespace ai
{
  namespace Search
  {
    /**
     * Base class for actions to evolve states during search
     */
    class Action
    {
    public:
      virtual ~Action();
      virtual void   Display() const;

    protected:
    private:
    };
  }
}

#endif /* _ACTION_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
