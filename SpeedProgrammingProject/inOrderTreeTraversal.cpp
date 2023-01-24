// A binary tree node has data, pointer to left child and a pointer to right child
#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> data;
        if (root != NULL) {

            vector<int> vector2 = inOrder(root->left);
            data.insert(data.end(), vector2.begin(), vector2.end());

            data.push_back(root->data);

            vector2 = inOrder(root->right);
            data.insert(data.end(), vector2.begin(), vector2.end());
        }
        return data;

    }
};