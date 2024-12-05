#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    };

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    };

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    };

private:
    void inorder(TreeNode* node, vector<int>& result) {
        if (node) {
            inorder(node->left, result);
            result.push_back(node->val);
            inorder(node->right, result);
        }
    };

    void preorder(TreeNode* node, vector<int>& result) {
        if (node) {
            result.push_back(node->val);
            preorder(node->left, result);
            preorder(node->right, result);
        }
    };

    void postorder(TreeNode* node, vector<int>& result) {
        if (node) {
            postorder(node->left, result);
            postorder(node->right, result);
            result.push_back(node->val);
        }
    };

    TreeNode* insert(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        
        if (val < root->val) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }

        return root;
    }
};

int main() {
    Solution sol;
    TreeNode* root = nullptr;

    cout << "Enter values to insert into the binary tree(type -1 to stop): " << endl;
    int value;
    while(true) {
        cin >> value;
        if (value == -1) {
            break;
        }
        root = sol.insert(root, value);
    }

    vector<int> inorderResult = sol.inorderTraversal(root);
    cout << "Inorder: ";
    for(int val : inorderResult) {
        cout << val << " ";
    }
    cout << endl;


    vector<int> preorderResult = sol.inorderTraversal(root);
    cout << "Presorder: ";
    for(int val : preorderResult) {
        cout << val << " ";
    }
    cout << endl;
    
    
    
    vector<int> postorder = sol.inorderTraversal(root);
    cout << "Postorder: ";
    for(int val : postorder) {
        cout << val << " ";
    }
    cout << endl;


    return 0;

}
