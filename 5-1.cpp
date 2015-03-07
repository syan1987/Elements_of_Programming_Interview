#include <iostream>
using namespace std;

// O(n), n is length
int getParity1(long n) {
    int count = 0;
    while (n) {
        count = (n&1)^count;
        n = n>>1;
    } 
    return count;
}

// O(n), n is num of 1's
int getParity2(long n) {
    int count = 0;
    while (n) {
        n = n & (n-1);
        count ^= 1;
    }
    return count;
}

// O(log(n)) n is length
int getParity3(long n) {
    n = (n >> 32) ^ n;
    n = (n >> 16) ^ n;
    n = (n >> 8) ^ n;
    n = (n >> 4) ^ n;
    n = (n >> 2) ^ n;
    n = (n >> 1) ^ n;
    
    n&=1;

    return n;
}

// O(1) table
int getParity4(long n) {
    n = (n >> 32) ^ n;
    n = (n >> 16) ^ n;
    n = (n >> 8) ^ n;
    n = (n >> 4) ^ n;
    n&=0xF;
    
    long array = 0b0110100110010110;
    return (array>>n)&1;
}

int main() {
    long input;
    while (cin >> input) {
        cout << getParity1(input) << endl;
        cout << getParity2(input) << endl;
        cout << getParity3(input) << endl;
        cout << getParity4(input) << endl;
    }
    return 0;
}
