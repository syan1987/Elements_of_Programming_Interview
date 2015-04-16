#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int _data;
    TreeNode* _left;
    TreeNode* _right;
    TreeNode(int data=0, TreeNode* left=NULL, TreeNode* right=NULL): _data(data),_left(left), _right(right) {}
};

void printTreeByDepth(TreeNode *root) {
    queue<TreeNode*> listOfNodes;
    int numOfNodes = 0;
    if (root != NULL) {
        numOfNodes++;
        listOfNodes.push(root);
    }
    // iterate until there are no nodes
    while (numOfNodes) {
        while (numOfNodes--) {
            TreeNode *next = listOfNodes.front();
            cout << next->_data << " ";
            listOfNodes.pop();
            if (next->_left != NULL) listOfNodes.push(next->_left);
            if (next->_right != NULL) listOfNodes.push(next->_right);
        }
        cout << endl;
        numOfNodes = listOfNodes.size();        
    }
} 

int main() {
    TreeNode t1(0), t2(1), t3(2), t4(3), t5(4), t6(5);
    t1._left = &t2;
    t1._right = &t3;
    t3._right = &t4;
    t4._left = &t5;
    t4._right = &t6;

    printTreeByDepth(&t1);

    return 0;
}
