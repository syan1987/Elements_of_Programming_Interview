#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<vector<string> > getAnagramGroup(vector<string> strings) {
    map<string, vector<string> > group;
    for (vector<string>::iterator it=strings.begin(); it<strings.end(); ++it) {
        string sortedString(*it);
        sort(sortedString.begin(),sortedString.end());
        group[sortedString].push_back(*it);
    }
    vector<vector<string> > result;
    for (map<string, vector<string> >::iterator it=group.begin(); it!=group.end(); ++it) {
        if (it->second.size()>1) {
            result.push_back(it->second);
        }
    }
    return result;
}

int main() {
    vector<string> test;
    test.push_back("abcdef");
    test.push_back("feabcd");
    vector<vector<string> > result = getAnagramGroup(test);
    cout << result.size() << endl;
    return 0;
}
