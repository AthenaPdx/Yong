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

   point(){}; // doesn't compile without defualt ctr
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


class rotationMatrix{
public:
   rotationMatrix(point& _angle){
       angle = _angle;
       init_x();
       init_y();
       init_z();
       cout << "init angle: " << angle;
       cout << "x--->" << endl;
       cout << X[0] << X[1] << X[2];
       cout << "y--->" << endl;
       cout << Y[0] << Y[1] << Y[2];
       cout << "z--->" << endl;
       cout << Z[0] << Z[1] << Z[2];
   }

   const point rotate_x(point&);
   const point rotate_y(point&);
   const point rotate_z(point&);

private:
   point X[3];
   point Y[3];
   point Z[3];
   point angle;
   
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
      Z[0] = point(cos(angle.z), -sin(angle.z),  0      );
      Z[1] = point(sin(angle.z),  cos(angle.z),   0      );
      Z[2] = point(0           ,   0,             1      );
   }
};

const point rotationMatrix::rotate_x(point& p){
      float x = p.x * X[0].x + p.y * X[0].y + p.z * X[0].z;
      float y = p.x * X[1].x + p.y * X[1].y + p.z * X[1].z;
      float z = p.x * X[2].x + p.y * X[2].y + p.z * X[2].z;
      point temp(x,y,z);
      return temp;
}


const point rotationMatrix::rotate_y(point& p){
      float x = p.x * Y[0].x + p.y * Y[0].y + p.z * Y[0].z;
      float y = p.x * Y[1].x + p.y * Y[1].y + p.z * Y[1].z;
      float z = p.x * Y[2].x + p.y * Y[2].y + p.z * Y[2].z;
      point temp(x,y,z);
      return temp;
}


const point rotationMatrix::rotate_z(point& p){
      float x = p.x * Z[0].x + p.y * Z[0].y + p.z * Z[0].z;
      float y = p.x * Z[1].x + p.y * Z[1].y + p.z * Z[1].z;
      float z = p.x * Z[2].x + p.y * Z[2].y + p.z * Z[2].z;
      point temp(x,y,z);
      return temp;
}




int main(){

   point angle(M_PI/4,M_PI/4,M_PI/4);
   rotationMatrix R(angle);

   point aaa(1,1,1);
   cout << endl;
   cout << "aaa: " << aaa;

   point rotate_x; 
   rotate_x = R.rotate_x(aaa);
   cout << "rotate_x: " << rotate_x;

   point rotate_y; 
   rotate_y = R.rotate_y(rotate_x);
   cout << "rotate_y: " << rotate_y;

   point rotate_z; 
   rotate_z = R.rotate_z(rotate_y);

   cout << "aaa-x-y-z: " << rotate_z;

   
   cout << endl;
   cout << "aaa: " << aaa;
   rotate_y = R.rotate_y(aaa);
   cout << "rotate_y: " << rotate_y;

   rotate_x = R.rotate_x(rotate_y);
   cout << "rotate_x: " << rotate_x;


   rotate_z = R.rotate_z(rotate_x);

   cout << "aaa-y-x-z: " << rotate_z;
   cout << "rotation matrices are not commutative" << endl;



   return 0;
}


