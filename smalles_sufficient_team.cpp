/*
https://leetcode.com/problems/smallest-sufficient-team/
*/

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) const noexcept {
        std::unordered_map<string, int> skillId;
        for (int i = 0; i < req_skills.size(); i++) {
            skillId[req_skills[i]] = i;
        }
        std::vector<int> skillsMaskOfPerson(people.size());
        for (int i = 0; i < people.size(); i++) {
            for (const std::string & skill : people[i]) {
                skillsMaskOfPerson[i] |= 1 << skillId[skill];
            }
        }
        std::vector<long long> dp(1 << req_skills.size(), (1LL << people.size()) - 1);
        dp[0] = 0;
        for (int skillsMask = 1; skillsMask < (1 << req_skills.size()); skillsMask++) {
            for (int i = 0; i < people.size(); i++) {
                int smallerSkillsMask = skillsMask & ~skillsMaskOfPerson[i];
                if (smallerSkillsMask != skillsMask) {
                    long long peopleMask = dp[smallerSkillsMask] | (1LL << i);
                    if (__builtin_popcountll(peopleMask) < __builtin_popcountll(dp[skillsMask])) {
                        dp[skillsMask] = peopleMask;
                    }
                }
            }
        }
        long long answerMask = dp[(1 << req_skills.size()) - 1];
        std::vector<int> ans;
        for (int i = 0; i < people.size(); i++) {
            if ((answerMask >> i) & 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};