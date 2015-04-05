#include <iostream>
#include <string>
using namespace std;

//replace 'a' with 'dd', remove 'b'
void replaceAndRemove(string & s) {
    int curLen = 0, numOfA = 0;
    for (int i=0; i<s.length(); i++) {
        if (s[i]!='b') {
            if (s[i]=='a') numOfA++;
            s[curLen++]=s[i];
        }
    }
    int totalLen = curLen + numOfA;
    s.resize(totalLen, ' ');
    
    for (int i=curLen-1; i>=0; i--) {
        if (s[i] == 'a') {
            s[--totalLen] = 'd';
            s[--totalLen] = 'd';
        } else {
            s[--totalLen] = s[i];
        }
    }
}

int main() {
    string s = "aaabbbcddx";
    replaceAndRemove(s);
    cout << s << endl;
}
