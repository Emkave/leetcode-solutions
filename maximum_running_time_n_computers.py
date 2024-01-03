'''
https://leetcode.com/problems/maximum-running-time-of-n-computers/
'''

class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        batteries.sort();
        carry = sum(batteries[:-n]);
        live = batteries[-n:];
        for i in range(n-1):
            if (carry // (i+1) < live[i+1]-live[i]):
                return live[i] + carry // (i + 1);
            
            carry -= (i + 1) * (live[i+1] - live[i]);
        
        return live[-1] + carry // n;