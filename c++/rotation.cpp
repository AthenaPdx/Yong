/*
build rotation matrix:

              ^ Y
              |
              |
              |
              |
              |              X
              ----------------> 
             /           
           /
         /          
       /
     / Z

*/

#include <iostream>
#include <cmath>

using namespace std;

struct point{
   point(){};
   point(point& other){
      x = other.x;
      y = other.y;
      z = other.z;
   }
   point& operator=(const point& other){
      x = other.x;
      y = other.y;
      z = other.z;
      return *this;
   }
   point(float _x, float _y, float _z):x(_x),y(_y),z(_z){};

   friend ostream& operator<<(ostream &out, const point& p){
      out << "(" << p.x << "," << p.y << "," << p.z << ")" << endl;
      return out;
   }

   float x, y, z;
};

int main(){
   point p1(1,2,3);
   point p3 = p1;
   cout << p3;
   return 0;
}

class rotationMatrix{
public:
   rotationMatrix(point& _angle){
       angle = _angle;
       init_x();;
       init_y();;
       init_z();;
   }

   void init_x(){
      X[0] = point(    1,         0,             0      );
      X[1] = point(    0,    cos(angle.x), -sin(angle.x));
      X[2] = point(    0,    sin(angle.x),  cos(angle.x));
   }

   void init_y(){
      Y[0] = point(cos(angle.y),  0,       sin(angle.y));
      Y[1] = point(    0,         1,             0      );
      Y[2] = point(-sin(angle.y), 0,       cos(angle.y));
   }

   void init_z(){
      Z[0] = point(cos(angle.y), -sin(angle.y),  0      );
      Z[1] = point(sin(angle.z),  cos(angle.z),   0      );
      Z[2] = point(0           ,   0,             1      );
   }
private:
   point X[3];
   point Y[3];
   point Z[3];
   point XYZ[3];
   point angle;
};
