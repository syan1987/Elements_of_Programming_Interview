#include <map>
#include <iostream>
#include <string>
using namespace std;

bool check(const string &L, const string &M){
    map<char, int> hashTable;
    for (string::const_iterator it=M.begin(); it<M.end(); it++) {
        hashTable[*it]++;
    }

    for (string::const_iterator it=L.begin(); it<L.end(); it++) {
        if (hashTable.count(*it) && hashTable[*it]>0) {
            hashTable[*it]--;
        } else {
            return false;
        }
    }
    return true;
}


int main() {
    string L, M;
    while (cin>>L>>M) {
        cout << check(L,M) << endl;
    }
    return 0;
}
