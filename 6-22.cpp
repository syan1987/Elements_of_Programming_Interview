#include <iostream>
#include <vector>
using namespace std;

void print2dArray (vector<vector<int> > array, int left, int right) {
    if (left>right) return;
    if (left==right) {
        cout << array[left][left] << " ";
        return;
    }
    for (int i=left; i<right; i++) {
        cout << array[left][i] << " ";
    }
    for (int i=left; i<right; i++) {
        cout << array[i][right] << " ";
    }
    for (int i=right; i>left; i--) {
        cout << array[right][i] << " ";
    }
    for (int i=right; i>left; i--) {
        cout << array[i][left] << " ";
    }
    print2dArray(array, left+1, right-1);
}

int main () {
    vector<vector<int> > array;
    int row1a[] = {1,2,3,4};
    int row2a[] = {12,13,14,5};
    int row3a[] = {11,16,15,6};
    int row4a[] = {10,9,8,7};
    vector<int> row1(row1a, row1a+4);
    vector<int> row2(row2a, row2a+4);
    vector<int> row3(row3a, row3a+4);
    vector<int> row4(row4a, row4a+4);
    array.push_back(row1);
    array.push_back(row2);
    array.push_back(row3);
    array.push_back(row4);

    print2dArray(array, 0, 3);

    return 0;
}
