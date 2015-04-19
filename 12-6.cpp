#include <iostream>
#include <vector>
using namespace std;

int findResult(int k) {
    int l = 0, r = k;
    while (l <= r) {
        int mid = l+(r-l)/2;
        if (mid*mid <= k) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    return l-1;
}

int main() {
    int k;
    while (cin >> k) {
        cout << findResult(k) << endl;
    }
    return 0;
}
