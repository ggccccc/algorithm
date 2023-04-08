//
// Created by Administrator on 2023/4/8.
//

#include <vector>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Tree {
    // 非递归方法实现前序遍历
    vector<int> preorderTraversal(TreeNode *root) {
        // write code here
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            res.push_back(node->val);
            if (node->right) {
                s.push(node->right);
            }
            if (node->left) {
                s.push(node->left);
            }
        }
        return res;
    }

    // 非递归方法实现中序遍历
    vector<int> inorderTraversal(TreeNode *root) {
        // write code here
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        stack<TreeNode *> s;
        while (!s.empty() || root != nullptr) {
            if (root != nullptr) {
                s.push(root);
                root = root->left;
            } else {
                TreeNode *node = s.top();
                s.pop();
                res.push_back(node->val);
                root = node->right;
            }
        }
        return res;
    }

    // 非递归方法实现后序遍历
    vector<int> postorderTraversal(TreeNode *root) {
        // write code here
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        s1.push(root);
        while (!s1.empty()) {
            TreeNode *node = s1.top();
            s1.pop();
            s2.push(node);
            if (node->left) {
                s1.push(node->left);
            }
            if (node->right) {
                s1.push(node->right);
            }
        }
        while (!s2.empty()) {
            res.push_back(s2.top()->val);
            s2.pop();
        }
        return res;
    }

    // 层序遍历，并存储每一层的所有节点
    vector<vector<int> > levelOrder(TreeNode *root) {
        // write code here
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        queue < TreeNode * > q;
        q.push(root);
        int cnt = 1;
        int cntNext = 0;
        vector<int> tmp;
        while (!q.empty()) {
            TreeNode *node = q.front();
            tmp.push_back(node->val);
            q.pop();
            if (node->left != nullptr) {
                q.push(node->left);
                cntNext++;
            }
            if (node->right != nullptr) {
                q.push(node->right);
                cntNext++;
            }
            cnt--;
            if (cnt == 0) {
                res.push_back(tmp);
                tmp.clear();
                cnt = cntNext;
                cntNext = 0;
            }

        }
        return res;
    }
};