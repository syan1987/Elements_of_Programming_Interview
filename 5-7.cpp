#include <iostream>
using namespace std;

double getExp(double x, int y) {
    double result = 1;
    if(y<0) {
        y = -y;
        x = 1.0 / x;
    }
    while (y) {
        int lastBit = y&1;
        if (lastBit) {
            result*=x;
        }
        x*=x;
        y >>= 1;
    }
    return result;
}

int main() {
    cout << getExp(2, -4) << endl;
    return 0;
}
