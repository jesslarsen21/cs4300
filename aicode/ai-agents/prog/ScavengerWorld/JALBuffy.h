#ifndef _JALBUFFY_H_
#define _JALBUFFY_H_

#include <ai_scavenger.h>
#include "JALBuffyModel.h"

namespace JAL
{
  namespace JALBuffy
  {
    class Buffy : public ai::Agent::AgentProgram
    {
    public:
      Buffy(ai::Agent::Options *opts);
      ~Buffy();
      virtual ai::Agent::Action * Program(const ai::Agent::Percept * percept);
    protected:
      worldContainer mModel;
    private:
    };
    
    
   class State : public ai::Search::State
   {
      public:
         State();
         State(double x, double y, double z, double charge);
         ~State();
         //virtual bool IsEqual(const State * const state_in) const;
         
         double getX();
         double getY();
         double getZ();
         double getCharge();
         
         void setX(double x);
         void setY(double y);
         void setZ(double z);
         void setCharge(double charge);
         
      protected:
         double mX, mY, mZ, mCharge;
      
   };
      
   class Action : public ai::Search::Action
   {
      public:
         Action();
         Action(int action);
         ~Action();
         
         int getAction();
         
         void setAction(int action);
         
      private:
         int mAction;
   
   };
   
  }
}

#endif /* _SNORLAX_H_ */
