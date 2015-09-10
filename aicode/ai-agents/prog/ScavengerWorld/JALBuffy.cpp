#include "JALBuffy.h"
#include "JALBuffyModel.h"
#include <cstdio>
#include <cmath>
#include <cstring>

double EPSILON = 0.00001;

namespace JAL
{
  namespace JALBuffy
  {
    /* For more on options look at the files:
     * ai-lib/include/Agent/Options.h
     * ai-lib/src/Agent/Options.cpp
     * al-lib/src/Agent/AgentDriver.cpp
     */
    /*
     * Run with:
     * ./RunProg ./SA_Test -a s -U 1
     */
    Buffy::Buffy(ai::Agent::Options *opts)
    {
      SetName("Buffy");
      std::cout << "The value of the -U option is: " << opts->GetArgInt("user1") << std::endl;
      //mModel();
    }

    Buffy::~Buffy()
    {
    }

   ai::Agent::Action * Buffy::Program(const ai::Agent::Percept * percept)
   {
    
      std::stringstream  ss;
      double             cell_x, cell_y, cell_z;
      std::string        cell_north, cell_south, cell_east, cell_west;
      
      
      double X_LOCATION;
      ss.str(percept->GetAtom("X_LOC").GetValue()); ss.clear();
      ss >> X_LOCATION;
      
      double Y_LOCATION;
      ss.str(percept->GetAtom("Y_LOC").GetValue()); ss.clear();
      ss >> Y_LOCATION;
      
      double Z_LOCATION;
      ss.str(percept->GetAtom("Z_LOC").GetValue()); ss.clear();
      ss >> Z_LOCATION;
         
      //add location into mModel
      coord Location;//(X_LOCATION, Y_LOCATION, Z_LOCATION);
      Location.x = X_LOCATION;
      Location.y = Y_LOCATION;
      Location.z = Z_LOCATION;
      mModel.setLocation(Location);   
      
      
      unsigned int i;
      for(i = 0; i < percept->NumAtom(); i++)
      {
         if(percept->GetAtom(i).GetName().substr(0,5) == "CELL_")
         {  
            //Add or update all cells in mModel.mCells
               
            // retrieve the ID
            double ID;
            std::string cellID = percept->GetAtom(i).GetName().substr(6);
            std::stringstream newss;
            newss.str(cellID); newss.clear();
            newss >> ID;
               
            // retrieve x, y, z, 
            
            std::string value = percept->GetAtom(i).GetValue();
            ss.str(value); ss.clear();
            
            ss >> cell_x; ss.ignore();
            ss >> cell_y; ss.ignore();
            ss >> cell_z; ss.ignore();
            
            std::getline(ss, cell_north, ',');
            std::getline(ss, cell_south, ',');
            std::getline(ss, cell_east,  ',');
            std::getline(ss, cell_west,  ',');
            
            // create temporary location key for map
            
            coord temp;//(cell_x, cell_y, cell_z);
            temp.x = cell_x;
            temp.y = cell_y;
            temp.z = cell_z;
              
            // add cell to mCells
               
            mModel.addCell(temp, cell(ID, cell_x, cell_y, cell_z, cell_north, cell_south, cell_east, cell_west));
         }
      }
            //find location cell
            
            cell loc = mModel.getCell(mModel.getLocation());
            
            std::string currNorth = loc.getNorth();
            std::string currEast = loc.getEast();
            std::string currSouth = loc.getSouth();
            std::string currWest = loc.getWest();
               
            if(currNorth == "plain" || currNorth == "mud")
            {
               ai::Scavenger::Action *action = new ai::Scavenger::Action;
      
               action->SetCode(ai::Scavenger::Action::GO_NORTH);
               return action;
            }
               
            else if(currEast == "plain" || currEast == "mud")
            {
               ai::Scavenger::Action *action = new ai::Scavenger::Action;
      
               action->SetCode(ai::Scavenger::Action::GO_EAST);
               return action;
            }
               
            else if(currWest == "plain" || currWest == "mud")
            {
               ai::Scavenger::Action *action = new ai::Scavenger::Action;
      
               action->SetCode(ai::Scavenger::Action::GO_WEST);
               return action;
            }
               
            else if(currSouth == "plain" || currSouth == "mud")
            {
               ai::Scavenger::Action *action = new ai::Scavenger::Action;
      
               action->SetCode(ai::Scavenger::Action::GO_SOUTH);
               return action;
            }
               
            else
            {
               ai::Scavenger::Action *action = new ai::Scavenger::Action;
      
               action->SetCode(ai::Scavenger::Action::QUIT);
               return action;
            }
    }
    
    //State Class
    
    State::State() : mX(0), mY(0), mZ(0), mCharge(0) { }
    
    State::State(double x, double y, double z, double charge) : mX(x), mY(y), mZ(z), mCharge(charge) { }
    
    State::~State() { }
    /*
    bool State::IsEqual(const State * const state_in) const
    {
      if (state_in->getX() == getX())
      {
         if(state_in->getY() == getY())
         {
            if(state_in->getCharge() == getCharge())
            {
               return true;
            }
         }
      
      }
      
      return false;
      
    }
    */   
    double State::getX()
    {
      return mX;
    }
    double State::getY()
    {
      return mY;
    }
    
    double State::getZ()
    {
      return mZ;
    }
    
    double State::getCharge()
    {
      return mCharge;
    }
         
    void State::setX(double x)
    {
      mX = x;
      return;
    }
    void State::setY(double y)
    {
      mY = y;
      return;
    }
    
    void State::setZ(double z)
    {
      mZ = z;
      return;
    }
    void State::setCharge(double charge)
    {
      mCharge = charge;
    }
    
    
      Action::Action() : mAction(0) { }
      Action::Action(int action) : mAction(action) { }
      Action::~Action() { }
         
      int Action::getAction()
      {
         return mAction;
      }
         
      void Action::setAction(int action)
      {
         mAction = action;
         return;
      }
    
  }
}

