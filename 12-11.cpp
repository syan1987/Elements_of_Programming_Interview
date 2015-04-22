#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> & a) {
    for (vector<int>::iterator it=a.begin(); it!=a.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int findKLargest(vector<int>& array, int left, int right, int k) {
    int pivot = left;
    int originalRight = right;
    int randomNum = array[pivot];//Set the first element as the random number as pivot.
    
    // move bigger elements to left, smaller to right
    while (true) {
        while(array[left]>=randomNum && left<=right) {
            left++;
        }
        while(array[right]<randomNum && left<=right) {
            right--;
        }
        if (left<right) {
            int tmp = array[left];
            array[left] = array[right];
            array[right] = tmp;
        }else {
            int tmp = array[right];
            array[right] = randomNum;
            array[pivot] = tmp;
            break;
        }
    }
    // if pivot is the k element, we find the k largest number
    if (right == k) {
        return randomNum;
    } else if (right > k) {
        // the k element is in left partation
        return findKLargest(array, pivot, right-1, k);
    } else {
        // the k element is in right partation
        return findKLargest(array, right+1, originalRight, k);
    }
    
}


int main() {
    int array[] = {4,2,10,3,88,33,44,23,99,71};
    vector<int> a(array, array+10);
    cout << "Array:";
    printVector(a);
    int k;
    while (cin >> k) {
        cout << findKLargest(a, 0, 9, k) << endl;
    }
    
    return 0;
}
