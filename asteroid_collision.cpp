/*
https://leetcode.com/problems/asteroid-collision/
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) const noexcept {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(nullptr); 
        std::cout.tie(nullptr);
        std::cerr.tie(nullptr);

        std::deque<int> stack;

        for(int i=0; i<asteroids.size(); i++){
            if(stack.empty() || asteroids[i] > 0){
                stack.push_back(asteroids[i]);
            }
            else{
                while(true){
                    int top = stack.back();
                    if(top<0){
                        stack.push_back(asteroids[i]);
                        break;
                    }
                    else if(top==-asteroids[i]){
                        stack.pop_back();
                        break;
                    }
                    else if(top>-asteroids[i]){
                        break;
                    }
                    else{
                        stack.pop_back();
                        if(stack.empty()){
                            stack.push_back(asteroids[i]);
                            break;
                        }
                    }
                }
            }
        }

        return std::vector<int>(stack.begin(), stack.end());
    }
};
