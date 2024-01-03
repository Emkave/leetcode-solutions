/*
https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
*/


class Solution {
public:
    double tr(std::vector<int> & dist, int speed) {
        double time = 0;
        for (int i=0; i<dist.size(); i++) {
            double t = static_cast<double>(dist[i]) / static_cast<double>(speed);
            time += (i == dist.size() - 1) ? t : ceil(t);
        }
        return time;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) noexcept {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        std::cerr.tie(nullptr);

        int l = 1, r = 1e7, mn = -1;
        
        while (l <= r) {
            int m = (l + r) / 2;
            if (this->tr(dist, m) <= hour) {
                mn = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return mn;
    }
};