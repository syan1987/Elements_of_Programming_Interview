#include <iostream>
#include <vector>

using namespace std;

bool twoCreate(const vector<int> &array, int k) {
    int left = 0; int right = array.size()-1;
    while(left<right) {
        if(array[left]+array[right]<k) {
            left++;
        } else if (array[left]+array[right]>k) {
            right--;
        } else {
            return true;
        }
    }
    return false;
}

bool threeCreate(const vector<int> &array, int k) {
    for (vector<int>::const_iterator it=array.begin(); it!=array.end(); ++it) {
        if (twoCreate(array, k-*it)) {
            return true;
        }
    }
    return false;
}


int main() {
    vector<int> A;
    A.push_back(-1);
    A.push_back(1);
    A.push_back(3);
    A.push_back(6);

    cout << threeCreate(A, 8) << endl;
    return 0;
}
