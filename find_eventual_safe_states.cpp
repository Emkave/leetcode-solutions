// https://leetcode.com/problems/find-eventual-safe-states/

class Solution {
    bool helper(int node, std::vector<std::vector<int>> & adj, std::vector<bool> & visited, std::vector<bool> & inStack) noexcept {
        if (inStack[node]) {
            return true;
        }

        if (visited[node]) {
            return false;
        }

        visited[node] = true;
        inStack[node] = true;

        for(const auto & it : adj[node]) {
            if (this->helper(it,adj,visited,inStack)) {
                return true;
            }
        }
        inStack[node] = false;
        return false;
    }
public:
    std::vector<int> eventualSafeNodes(std::vector<std::vector<int>> & graph) noexcept {
        const unsigned n = graph.size();
        std::vector<std::vector<int>> adj (n);

        for (unsigned i=0; i<n; i++) {
            for (const auto & it : graph[i]) {
                adj[i].emplace_back(it);
            }
        }

        std::vector<bool> visited (n), inStack (n);
        for (unsigned i=0; i<n; i++){
            this->helper(i, adj, visited,inStack);
        }

        std::vector<int> safeNodes;
        for (unsigned i=0; i<n; i++){
            if (!inStack[i]) {
                safeNodes.emplace_back(i);
            }
        }
        return safeNodes;
    }
};