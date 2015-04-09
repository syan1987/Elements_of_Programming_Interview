#include <iostream>
using namespace std;

struct ListNode {
    int _data;
    ListNode* _next;
    ListNode(int data=0, ListNode* next=NULL):_data(data),_next(next) {
    }
};

ListNode* checkCircle(ListNode* root) {
    ListNode* slow = root, *fast = root;
    while (fast && fast->_next && fast->_next->_next) {
        fast = fast->_next->_next;
        slow = slow->_next;
        // found circle 
        if (fast == slow) {
            int len = 1;
            while(fast->_next != slow) {
                len++;
                fast = fast->_next;
            }
            fast = root;
            slow = root;
            while (len--) {
                fast = fast->_next;
            }
            while (slow!=fast) {
                slow=slow->_next;
                fast=fast->_next;
            }
            return slow;

        }
    }
    return NULL;
}

int main() {
    return 0;
}
