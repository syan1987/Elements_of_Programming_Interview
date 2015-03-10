#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int _data;
    TreeNode* _left;
    TreeNode* _right;
    TreeNode(int data=0, TreeNode* left=NULL, TreeNode* right=NULL): _data(data),_left(left), _right(right) {}
};

//Check balance of the current true with root at root.
//If balanced, return true and set height.
//If not balanced, return false and not set height.
bool checkBalance(TreeNode* root, int &height) {
    if (!root) {
        height=0;
        return true;
    }
    int leftHeight;
    if (!checkBalance(root->_left, leftHeight)) {
        return false;
    }
    int rightHeight;
    if (!checkBalance(root->_right, rightHeight)) {
        return false;
    }
    bool isBalanced = abs(leftHeight-rightHeight)<=1;
    if (!isBalanced) {
        return false;
    }
    height = max(leftHeight,rightHeight)+1;
    return true;
}

int main() {
    TreeNode node1, node2, node3;
    node1._left = &node2;
    node2._left = &node3;
    int height=0;
    cout << checkBalance(&node1, height) << endl;
    cout << height << endl;
    return 0;
}
