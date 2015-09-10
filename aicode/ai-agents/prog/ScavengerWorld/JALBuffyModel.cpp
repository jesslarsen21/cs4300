#include "JALBuffyModel.h"
namespace JAL
{
   namespace JALBuffy
   {
   
      worldContainer::worldContainer()
      {
         coord temp;
         temp.x = 0;
         temp.y = 0;
         temp.z = 0;
         setLocation(temp);
         setGoal(temp);
         
         setHitPoints(0);
         setCharge(0);
         setBase(0);
      }
   
      worldContainer::worldContainer(coord Location, coord Goal, double Charge, double Base, double HitPoints)
      {
         setLocation(Location);
         setGoal(Goal);
         setCharge(Charge);
         setBase(Base);
         setHitPoints(HitPoints);
      }
   
      coord worldContainer::getLocation()
      {
         return mLocation;
      }
      coord worldContainer::getGoal()
      {
         return mGoal;
      }
      double worldContainer::getHitPoints()
      {
         return mHitPoints;
      }
      double worldContainer::getCharge()
      {
         return mCharge;
      }
      double worldContainer::getBase()
      {
         return mBase;
      }
      
      void worldContainer::setLocation(coord Location)
      {
         mLocation = Location;
         return;
      }
      void worldContainer::setGoal(coord Goal)
      {
         mGoal = Goal;
         return;
      }
      void worldContainer::setHitPoints(double hitpoints)
      {
         mHitPoints = hitpoints;
         return;
      }
      void worldContainer::setCharge(double charge)
      {
         mCharge = charge;
         return;
      }
      void worldContainer::setBase(double Base)
      {
         mBase = Base;
         return;
      }
      void worldContainer::addCell(coord location, cell newCell)
      {
         mCells[location] = newCell;
         return;
      }
      
      
      cell worldContainer::getCell(coord key)
      {
         return mCells[key];
      }
      
      cell::cell()
      {
         setID(0);
         setX(0);
         setY(0);
         setZ(0);
      }

      cell::cell(double ID, double X, double Y, double Z, std::string North, std::string South,std::string East, std::string West)
      {
         setID(ID);
         setX(X);
         setY(Y);
         setZ(Z);
         setNorth(North);
         setSouth(South);
         setEast(East);
         setWest(West);
         
      }
      

      double cell::getID()
      {
         return mID;
      }
      double cell::getX()
      {
         return mX;
      }
      double cell::getY()
      {
         return mY;
      }
      double cell::getZ()
      {
         return mZ;
      }
      std::string cell::getSouth()
      {
         return mSouth;
      }
      std::string cell::getNorth()
      {
         return mNorth;
      }
      std::string cell::getEast()
      {
         return mEast;
      }
      std::string cell::getWest()
      {
         return mWest;
      }
            
      void cell::setID(double ID)
      {
         mID = ID;
         return;
      }
      
      void cell::setX(double X)
      {
         mX = X;
         return;
      }
      void cell::setY(double Y)
      {
         mY = Y;
         return;
      }
      void cell::setZ(double Z)
      {
         mZ = Z;
         return;
      }
      void cell::setSouth(std::string South)
      {
         mSouth = South;
         return;
      }
      void cell::setNorth(std::string North)
      {
         mNorth = North;
         return;
      }
      void cell::setEast(std::string East)
      {
         mEast = East;
         return;
      }
      void cell::setWest(std::string West)
      {
         mWest = West;
      }
      
      
      bool operator <(coord const& one, coord const& two)
      {
         if (one.x != two.x) return one.x < two.x;
         if (one.y != two.y) return one.y < two.y;
         return one.z < two.z; 
      }
      
   }        
}
