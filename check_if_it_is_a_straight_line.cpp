// https://leetcode.com/problems/check-if-it-is-a-straight-line/

class Solution {
public:
    bool checkStraightLine(std::vector<std::vector<int>> coordinates) {
        // (a2 - a1)(d2-d1) == (b2-b1)(c2-c1)
        //    dx1     dy2        dy1    dx2

        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(NULL);
        std::cout.tie(NULL);

        const int dx = coordinates[1][0] - coordinates[0][0];
        const int dy = coordinates[1][1] - coordinates[0][1];

        for (unsigned short i=2; i<coordinates.size(); i++) {
            if (dx * (coordinates[i][1]-coordinates[0][1]) != dy * (coordinates[i][0]-coordinates[0][0])) {
                return false;
            }
        }

        return true;
    }
};