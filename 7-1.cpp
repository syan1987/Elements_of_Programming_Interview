#include <iostream>
#include <string>
using namespace std;

string int2string(int num) {
    string result;
    bool pos = true;
    if (num<0) {
        num*=-1;
        pos = false;
    }
    while(num) {
        result.push_back('0'+num%10);
        num/=10;
    }
    if (!pos) result.push_back('-');
    int len = result.length();
    for (int i=0; i<len/2; i++) {
        char tmp = result[i];
        result[i] = result[len-1-i];
        result[len-1-i] = tmp;
    }
    if (len==0) result = "0";
    return result;
}

int string2int(const string &num) {
    int result = 0;
    bool pos= true;
    for (int i=0; i<num.length(); i++) {
        if (num[i] == '-') pos = false;
        else {
            int digit = num[i]-'0';
            result=result*10+digit;
        }
    }
    if (!pos) return (-result);
    return result;
}

int main() {
    int input;
    while(cin >> input) {
        cout << int2string(input) << endl;
        cout << string2int(int2string(input)) << endl;
    }
}
