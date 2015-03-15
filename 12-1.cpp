#include <iostream>
#include <vector>
using namespace std;

int findFirstIndex(const vector<int>& array, int key) {
    int L = 0, U = array.size()-1;
    int result = -1;
    while(L<=U) {
        int M = L + (U-L)/2;
        if (array[M]<key) {
            L = M+1;
        } else if(array[M]>key) {
            U = M-1;
        } else {//found, keep search the lower part
            result = M;
            U = M-1;
        }
    }
    return result;
}

int main() {
    int myints[] = {4,4,5,5,5,10,11,11,11,33};
    vector<int> test(myints, myints+10);
    cout << findFirstIndex(test, 11) << endl;
    return 0;
}
