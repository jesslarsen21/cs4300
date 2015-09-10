#ifndef _JALBUFFYMODEL_H
#define _JALBUFFYMODEL_H

#include <cstring>
#include <map>
//world container
#include <string>
namespace JAL
{

   namespace JALBuffy
   {
   
      struct coord
      {
         //coord(double newx, double newy, double newz) : x(newx), y(newy), z(newz) { }
         double x, y, z;
         //overload less than operator:
         /*bool operator <(coord const& rhs)
         {
            if (x != rhs.x) return x < rhs.x;
            if (y != rhs.y) return y < rhs.y;
            return y < rhs.y; 
         }*/
      };
      
      class cell
      {
         public:
            cell();
            cell(double ID, double X, double Y, double Z, std::string North, std::string South,std::string East, std::string West);
            double getID();
            double getX();
            double getY();
            double getZ();
            std::string getSouth();
            std::string getNorth();
            std::string getEast();
            std::string getWest();
            
            void setID(double ID);
            void setX(double X);
            void setY(double Y);
            void setZ(double Z);
            void setSouth(std::string South);
            void setNorth(std::string North);
            void setEast(std::string East);
            void setWest(std::string West);
      
   
         private:
            double mID, mX, mY, mZ;
            std::string mSouth, mNorth, mEast, mWest; 
            

            
      };
      
      class worldContainer
      {
         public:
            worldContainer();
            worldContainer(coord Location, coord Goal, double Charge, double Base, double HitPoints);
            coord getLocation();
            coord getGoal();
            double getHitPoints();
            double getCharge();
            double getBase();
            cell getCell(coord key);
            
            void setLocation(coord Location);
            void setGoal(coord Goal);
            void setHitPoints(double hitpoints);
            void setCharge(double charge);
            void setBase(double Base);
            
            void addCell(coord location, cell newCell);
            
         protected:
         
         private:
            double mHitPoints;
            double mCharge;
            double mBase;
            coord mGoal;
            coord mLocation;
            
            std::map< coord, cell > mCells;
      
      };
      
   }
      
}

#endif
      
