#include <iostream>
using namespace std;

struct BSTNode{
    int _data;
    BSTNode *_left;
    BSTNode *_right;
    BSTNode(int data=0, BSTNode *left=NULL, BSTNode *right=NULL) : _data(data), _left(left), _right(right) {}
};

bool isBST(BSTNode *root, int low, int high) {
    if (!root) {
        return true;
    } else if (root->_data<low ||root->_data>high) {
        return false;
    }
    return isBST(root->_left, low, root->_data) && isBST(root->_right, root->_data, high);
}

int main() {
    BSTNode n1(1), n2(4), n3(3, &n1, &n2);
    cout << isBST(&n3, INT_MIN, INT_MAX) << endl;
    
}
