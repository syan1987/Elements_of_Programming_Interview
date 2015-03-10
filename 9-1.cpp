#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct Stack {
    void push(int n) {
        data.push_back(n); 
        if (!tracking.empty()) {
            pair<int, int> &tmp = tracking.back();
            if (tmp.first==n) {
                tmp.second++;
                return;
            } else if(tmp.first>n) {
                return;
            }
        }
        tracking.push_back(make_pair(n,1));
    }
    bool pop(int& n) {
        if (data.empty()) return false;
        n = data.back();
        data.pop_back();
        
        pair<int, int> &tmp = tracking.back();
        if (tmp.first == n) {
            if (tmp.second>1) {
                tmp.second--;
            } else {
                tracking.pop_back();
            }
        }
        return true;
    }
    bool max(int &n) {
        if (tracking.empty()) return false;
        pair<int, int> &tmp = tracking.back();
        n = tmp.first;
        return true;
    }
    vector<int> data;
    vector<pair<int, int> > tracking;
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(2);
    stack.push(1);
    stack.push(3);
    int tmp;
    if (stack.max(tmp))
        cout << "max:" << tmp << endl;
    while (stack.pop(tmp)) {
        cout << "pop out:" << tmp << endl;
        if (stack.max(tmp))
        cout << "max:" << tmp << endl;
    }
    return 0;
}
