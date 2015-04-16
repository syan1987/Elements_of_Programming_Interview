#include <iostream>
using namespace std;


struct TreeNode {
    int _data;
    TreeNode* _parent;
    TreeNode(int data=0, TreeNode* parent=NULL): _data(data), _parent(parent) {}
};

int getDepth(TreeNode *n) {
    int depth = 0;
    while(n->_parent) {
        depth++;
        n=n->_parent;
    }
    return depth;
}

TreeNode * findLCA(TreeNode *n1, TreeNode *n2) {
    int n1Depth = getDepth(n1);
    int n2Depth = getDepth(n2);
    // Save the node with smaller depth in n1
    if (n1Depth>n2Depth) {
        TreeNode *tmp = n2;
        n2 = n1;
        n1 = tmp;
    }
    // Go upside from n2 to arrive the same depth of n1
    while (n2Depth>n1Depth) {
        n2 = n2->_parent;
        n2Depth--;
    }
    // Go upside from n1 and n2 at the same time
    while (n1!=n2) {
        n1=n1->_parent;
        n2=n2->_parent;
    }
    return n1;
}

int main() {
    TreeNode t1(0), t2(1), t3(2), t4(3), t5(4), t6(5);
    t2._parent = &t1;
    t3._parent = &t1;
    t4._parent = &t2;
    t5._parent = &t3;
    t6._parent = &t3;
    
    cout << findLCA(&t4, &t6)->_data << endl;

    return 0;
}
