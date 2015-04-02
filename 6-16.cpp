#include <iostream>
#include <vector>
#include <random>
using namespace std;

void getSubset(vector<int>& array, int k) {
    default_random_engine gen((random_device())());
    for (int i=0; i<k; i++) {
        uniform_int_distribution<int> dis(i, array.size()-1);
        swap(array[i],array[dis(gen)]); 
    }
}

int main() {
    int nums[] = {1,4,100,20,50,5,9,88,40,11};
    vector<int> array(nums, nums+10);
    getSubset(array, 3);
    cout << array[7] << " " << array[8] << " " << array[9] << endl;
    return 0;
}
