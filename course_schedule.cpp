/*
https://leetcode.com/problems/course-schedule/
*/

class Solution {
public:
    bool canFinish(const int numCourses, const vector<vector<int>> & prerequisites) const noexcept {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(NULL); 
        std::cout.tie(NULL);

        std::queue<int> q;
        int visited = 0;
        std::vector<int> indegrees (numCourses);
        std::vector<std::vector<int>> adj (numCourses);

        for (const auto & preq : prerequisites) {
            adj[preq[1]].emplace_back(preq[0]);
            indegrees[preq[0]]++;
        }

        for (int i=0; i<numCourses; i++) {
            if (!indegrees[i]) {
                q.emplace(i);
            }
        }

        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited++;

            for (const auto & neighbor : adj[node]) {
                indegrees[neighbor]--;
                if (!indegrees[neighbor]) {
                    q.emplace(neighbor);
                }
            }
        }
    

        return visited == numCourses;
    }
};