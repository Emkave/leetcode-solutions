// https://leetcode.com/problems/can-place-flowers/

class Solution {
public:
    inline bool canPlaceFlowers(vector<int>& flowerbed, int n) noexcept {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);

        for(int i=0; i<flowerbed.size(); i++){
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size()-1 || flowerbed[i+1] == 0)){
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};