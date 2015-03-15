#include <iostream>
#include <queue>
#include <utility>

using namespace std;

struct Compare{
    bool operator() (const pair<int, int>& left, const pair<int, int>& right) {
        return left.first > right.first;
    }
};

vector<int> mergeSortedArrays(vector<vector<int> >& sortedArrays) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, Compare > minHeap;
    vector<int> curIndexArray(sortedArrays.size(), 0);
    for(int i = 0; i < sortedArrays.size(); i++) {
        int curIndex = curIndexArray[i];
        if (curIndex<sortedArrays[i].size()) {
            minHeap.push(make_pair(sortedArrays[i][curIndex], i));
            curIndexArray[i]++;
        }

    }

    vector<int> result;
    while(minHeap.size()) {
        pair<int, int> top = minHeap.top();
        minHeap.pop();
        result.push_back(top.first);
        if (curIndexArray[top.second]<sortedArrays[top.second].size()) {
            minHeap.push(make_pair(sortedArrays[top.second][curIndexArray[top.second]++], top.second));
        }
    }
    return result;
}

int main() {
    int myints[] = {1, 2, 5, 10, 19, 3, 8, 13, 20, 150, 88, 99, 100, 120, 130};
    vector<vector<int> > test;
    vector<int> test1(myints, myints+5);
    vector<int> test2(myints+5, myints+10);
    vector<int> test3(myints+10, myints+15);
    
    test.push_back(test1);
    test.push_back(test2);
    test.push_back(test3);

    vector<int> result = mergeSortedArrays(test);
    for (vector<int>::iterator it=result.begin(); it!=result.end(); ++it) {
        cout << *it << endl;
    }
    return 0;

}
