#include <iostream>
#include <climits>
using namespace std;

int getCapacity(int * array, int len) {
    int result = 0;
    int minHeight = INT_MAX;
    for (int i=0; i<len; i++) {
        result = result >= (array[i] - minHeight) ? result : (array[i] - minHeight);
        minHeight = minHeight < array[i] ? minHeight : array[i];
    }
    return result;
}

int main() {
    int len = 10;
    int array[10] = {6,2,3,10,12,4,9,11,20,1};
    cout << getCapacity(array, len) << endl;
    return 0;
}
