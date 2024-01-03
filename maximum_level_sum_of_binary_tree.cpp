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
 * https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
 */
class Solution {
public:
    std::map<unsigned, int> map_;

    void get_levels(TreeNode * node, unsigned level) {
        if (node->left != nullptr) {
            this->get_levels(node->left, level + 1);
        }

        if (node->right != nullptr) {
            this->get_levels(node->right, level + 1);
        }

        this->map_[level] += node->val;
    }

    inline int get_max(void) {
        int max = 1;
        int lmax = this->map_[1];
        for (std::map<unsigned, int>::iterator iter = this->map_.begin(); iter != this->map_.end(); iter++) {
            if (iter->second > lmax) {
                max = iter->first;
                lmax = iter->second;
            }
        }
        return max;
    }

    int maxLevelSum(TreeNode* root) {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(NULL); 
        std::cout.tie(NULL);
        this->get_levels(root, 1);
        return get_max();
    }
};