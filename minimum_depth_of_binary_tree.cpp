/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/
 */
class Solution {
public:
    int depth = INT_MAX;
    
    void get_depth(TreeNode * node, int step) {
        node->val = 0;
        if (node->left != nullptr) {
            node->val = 1;
            this->get_depth(node->left, step + 1);
        }

        if (node->right != nullptr) {
            node->val = 1;
            this->get_depth(node->right, step + 1);
        }

        if (step < depth && node->val != 1) {
            depth = step;
        }
    }

    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        this->get_depth(root, 1);

        return depth;
    }
};