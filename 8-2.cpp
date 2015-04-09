#include <iostream>
using namespace std;

struct ListNode {
    int _data;
    ListNode* _next;
    ListNode(int data=0, ListNode* next=NULL):_data(data),_next(next) {
    }
};

ListNode* reverseList(ListNode *root) {
    ListNode *l = root, *r = root->_next;
    l->_next = NULL;
    while (r) {
        ListNode *rr = r->_next;
        r->_next = l;
        l = r;
        r = rr;
    }
    return l;
}

int main() {
    ListNode n4(4);
    ListNode n3(3, &n4);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);
    ListNode *root = &n1;
    root = reverseList(root);

    while (root) {
        cout << root->_data << endl;
        root=root->_next;
    }

    return 0;
}
