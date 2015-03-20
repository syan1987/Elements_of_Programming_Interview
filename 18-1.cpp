#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    double _data;
    TreeNode *_left;
    TreeNode *_right;
    TreeNode(double data = 0, TreeNode *left= NULL, TreeNode *right=NULL):_data(data), _left(left), _right(right) {}
};

struct Compare {
    bool operator()(const TreeNode* lhs, const TreeNode* rhs) {
        return lhs->_data > rhs->_data;
    }
};

TreeNode * getHuffmanTree(const vector<double>& weights) {
    priority_queue<TreeNode*, vector<TreeNode*>, Compare> list;
    for (vector<double>::const_iterator it = weights.begin(); it!=weights.end(); ++it) {
        list.push(new TreeNode(*it));
    }
    while (list.size()>1) {
        TreeNode *node1 = list.top();
        list.pop();
        TreeNode *node2 = list.top();
        list.pop();
        TreeNode *parent = new TreeNode(node1->_data+node2->_data, node1, node2);
        list.push(parent);
    }
    return list.size() ? list.top() : NULL;    
}

double getWepOfHuffmanTree(TreeNode * root, int depth) {
    if (root==NULL) return 0;
    if (root->_left==NULL && root->_right==NULL) return depth*root->_data;
    return getWepOfHuffmanTree(root->_left, depth+1) + getWepOfHuffmanTree(root->_right, depth+1);
}

int main() {
    vector<double> frequencies;
    double frequency;
    while (cin >> frequency) {
        if (frequency<0) break;
        frequencies.push_back(frequency);
    }

    cout << getWepOfHuffmanTree(getHuffmanTree(frequencies), 0) << endl;
    return 0;
}
