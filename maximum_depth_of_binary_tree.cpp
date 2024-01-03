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
 * 
 *  https://leetcode.com/problems/maximum-depth-of-binary-tree/
 */
class Solution {
public:
    int depth = 1;

    void get_depth(TreeNode * node, int step) noexcept {
        if (node->left != nullptr) {
            this->get_depth(node->left, step + 1);
        }

        if (node->right != nullptr) {
            this->get_depth(node->right, step + 1);
        }

        this->depth = (this->depth < step) ? step : this->depth;
    }

    int maxDepth(TreeNode * root) noexcept {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(nullptr); 
        std::cout.tie(nullptr);

        if (root == nullptr) {
            return 0;
        }

        this->get_depth(root, 1);

        return this->depth;
    }
};