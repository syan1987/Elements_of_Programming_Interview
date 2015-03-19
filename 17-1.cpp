#include <iostream>
#include <vector>
using namespace std;

vector<int> getPermutations(int k, const vector<int>& scores) {
    vector<int> result(k+1, 0);
    result[0] = 1;
    for (int i=0; i<=k; i++) {
        for (vector<int>::const_iterator it=scores.begin(); it!=scores.end(); ++it) {
            if (i>=*it) {
                result[i] += result[i-*it];
            }
        }
    }
    return result;
}

vector<int> getCombinations(int k, const vector<int>& scores) {
    vector<int> result(k+1, 0);
    result[0] = 1;
    for (vector<int>::const_iterator it=scores.begin(); it!=scores.end(); ++it) {
        for (int i=*it; i<=k; i++) {
            result[i] += result[i-*it];
        }
    }
    return result;
}

int main() {
    vector<int> scores;
    scores.push_back(1);
    scores.push_back(2);
    scores.push_back(10);
    vector<int> res1=getCombinations(10, scores);
    vector<int> res2=getPermutations(10, scores);
    cout << res1[10] << endl;
    cout << res2[10] << endl;
    return 0;
}
