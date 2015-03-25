#include <iostream>
#include <string>
using namespace std;

//convert a number(string s) from base1 system to base2 system
string convertBase(const string& s, int base1, int base2) {
    string result;
    long long sum = 0;
    for (int i = s[0]=='-'?1:0; i<s.length(); ++i) {
        sum *= base1;
        sum += isdigit(s[i]) ? s[i] - '0' : s[i] - 'A' +10;
    }

    while (sum) {
        int reminder = sum%base2;
        result.push_back(reminder<10?'0'+reminder:'A'+reminder-10);
        sum/=base2;
    }

    if (s[0]=='-') result.push_back('-');
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    cout << convertBase("-100", 10, 7) << endl;
    return 0;
}
