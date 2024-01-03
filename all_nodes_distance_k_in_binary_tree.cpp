// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

class Solution {
public:
    std::unordered_map<int, TreeNode*> parent;  // node value -> parent
    std::vector<int> ans;

    void findParents(TreeNode* node) {
        if (!node) return;
        if (node->left) {
            parent[node->left->val] = node;
            this->findParents(node->left);
        }
        if (node->right) {
            parent[node->right->val] = node;
            this->findParents(node->right);
        }
    }

    void dfs(TreeNode* node, TreeNode* prev, int k) {
        if (!node) return;
        if (k == 0) {
            ans.emplace_back(node->val);
            return;
        }
        if (node->left != prev) {
            this->dfs(node->left, node, k-1);
        }
        if (node->right != prev) {
            this->dfs(node->right, node, k-1);
        }
        if (parent[node->val] != prev) {
            this->dfs(parent[node->val], node, k-1);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(NULL); 
        std::cout.tie(NULL);
        this->findParents(root);
        this->dfs(target, NULL, k);
        return ans;
    }
};
