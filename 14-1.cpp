#include <iostream>
#include <set>
#include <vector>
using namespace std;

//Normal solution to get elements from two arrays. Just go through two arrays at the same time and collect the elements in common. O(m+n)
set<int> getCommonElementsV1(const vector<int>& a, const vector<int>& b) {
    vector<int>::const_iterator it_a = a.begin();
    vector<int>::const_iterator it_b = b.begin();
    set<int> result;
    
    while(it_a!=a.end() && it_b!=b.end()) {
        if(*it_a > *it_b) {
            it_b++;
        } else if(*it_a < *it_b) {
            it_a++;
        } else {
            result.insert(*it_a);
            it_a++;
            it_b++;
        }
    }
    return result;
}

//len(a)=n << len(b)=m, O(nlog(m))
set<int> getCommonElementsV2(const vector<int>& a, const vector<int>& b) {
    set<int> result;
    for (vector<int>::const_iterator it=a.begin(); it!=a.end(); ++it) {
        int target = *it;
        int left = 0, right = b.size()-1;
        while (left<=right) {
            int middle = left+(right-left)/2;
            if (b[middle]>target) {
                right = middle-1;
            } else if (b[middle]<target) {
                left = middle+1;
            } else {
                result.insert(target);
                break;
            }
        }
    }
    return result;
}

int main() {
    int myints[] = {1,2,5,9,10,1,5,8,10,20};
    vector<int> a(myints,myints+5);
    vector<int> b(myints+5,myints+10);
    set<int> result = getCommonElementsV2(a,b);
    //set<int> result = getCommonElementsV2(a,b);
    for (set<int>::iterator it=result.begin();it!=result.end();++it) {
        cout << *it << endl;
    }
    return 0;
}
