#include <iostream>
using namespace std;

struct ListNode {
    int _data;
    ListNode* _next;
    ListNode(int data=0, ListNode* next=NULL):_data(data),_next(next) {
    }
};

// Insert one list into another one
ListNode* mergeList1(ListNode* L, ListNode* F) {
    if (!L) return F;
    if (!F) return L;
    //decide which one is interted to which one.
    //fine the one with smallest number to be inserted.
    if (L->_data>F->_data) {
        ListNode* tmp = L;
        L = F;
        F = tmp;
    }
    ListNode* result = L;
    
    while(L->_next && F) {
        if (L->_next->_data>F->_data) {
            //insert element in F into L
            ListNode* LL = L->_next;
            L->_next = F;
            F = F->_next;
            L = L->_next;
            L->_next = LL;
        } else {
            L=L->_next;
        }
    }
    // if there are still elements in F, append it to the end of L
    if (F) {
        L->_next = F;
    }
    return result;
}

// Better solution keep a tail pointing the end of sorted list, and keep going through the rest of L and F
ListNode* mergeList2(ListNode* L, ListNode* F) {
    ListNode result;
    ListNode *tail = &result;
    while(L && F) {
        if (L->_data>F->_data) {
            tail->_next=F;
            tail=F;
            F=F->_next;
        } else {
            tail->_next=L;
            tail=L;
            L=L->_next;
        }
    }
    if (L) {
        tail->_next = L;
    }
    if (F) {
        tail->_next = F;
    }
    return result._next;
}


int main() {
    ListNode *L, *F;
    ListNode L1(4), L2(5), L3(7), F1(3), F2(11);
    L = &L1;
    L1._next = &L2;
    L2._next = &L3;

    F = &F1;
    F1._next = &F2;

    ListNode * result = mergeList2(L, F);

    while(result) {
        cout << result->_data << " ";
        result=result->_next;
    }
    cout << endl;

    return 0;
}
