#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, string> M;

void printPermutationOfPhoneNumber(string &s, int index, string &result) {
    if (index>=s.length()) {
        cout << result << endl;
        return;
    }
    if (M.count(s[index])) {
        string m = M[s[index]];
        for (string::iterator it=m.begin(); it!=m.end(); ++it) {
            result[index] = *it;
            printPermutationOfPhoneNumber(s, index+1, result);
        }
    } else {
        result[index] = s[index];
        printPermutationOfPhoneNumber(s, index+1, result);
    }
}

void printResult(string &s) {
    string result = s;
    printPermutationOfPhoneNumber(s, 0, result);
}

int main() {
    M.insert(make_pair('2', "ABC"));
    M.insert(make_pair('3', "DEF"));
    M.insert(make_pair('4', "GHI"));
    M.insert(make_pair('5', "JKL"));
    M.insert(make_pair('6', "MNO"));
    M.insert(make_pair('7', "PQRS"));
    M.insert(make_pair('8', "TUV"));
    M.insert(make_pair('9', "WXYZ"));

    string s = "123";
    printResult(s);
}
