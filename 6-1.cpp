#include <iostream>
using namespace std;

void swap(int * array, int left, int right) {
    int tmp = array[left];
    array[left] = array[right];
    array[right] = tmp;
}

void countSort(int * array, int len, int index) {
    int leftP = 0, rightP = len-1, middleLP = index, middleRP = index;
    while (leftP<middleLP) {
        if (array[leftP]<array[middleLP]) {
            leftP++;
        } else if (array[leftP]==array[middleLP]) {
            middleLP--;
            swap(array, leftP, middleLP);
        } else {
            swap(array, leftP, middleRP);
            middleRP--;
            middleLP--;
            swap(array, leftP, middleLP);
        }
    }

    while (rightP>middleRP) {
        if (array[rightP]>array[middleRP]) {
            rightP--;
        } else if (array[rightP]==array[middleRP]) {
            middleRP++;
            swap(array, rightP, middleRP);
        } else {
            swap(array, rightP, middleLP);
            middleLP++;
            middleRP++;
            swap(array, rightP, middleRP);
        }
    }
}



int main() {
    int len = 10, index = 7;
    int array[10] = {5,4,3,7,11,4,6,7,3,22};
    countSort(array, len, index);
    for (int i = 0; i<len; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}
