#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

struct Star{
    int _x;
    int _y;
    int _z;
    Star(int x=0, int y=0, int z=0):_x(x), _y(y), _z(z) {}
    double getDistance() const {return sqrt(_x*_x+_y*_y+_z*_z);}
};

struct MyComparison
{
    MyComparison() {}
    bool operator() (const Star& lhs, const Star&rhs) const
    {
        return lhs.getDistance()<rhs.getDistance();
    }
};

int main() {
    priority_queue<Star, vector<Star>, MyComparison> myList;
    int x, y, z;
    int k = 3;
    while (cin >> x >> y >> z) {
        if (x==0 && y==0 && z==0) break;
        Star s(x, y, z);
        myList.push(s);
        if (myList.size()>k) {
            myList.pop();
        }
    }
    while (!myList.empty()) {
        Star s = myList.top();
        cout << s._x << " " << s._y << " " << s._z << endl;
        myList.pop(); 
    }
    return 0;
}
