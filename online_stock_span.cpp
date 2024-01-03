/*
https://leetcode.com/problems/online-stock-span/
*/

class StockSpanner {
public:
    std::stack<std::pair<int, int>> stack;

    explicit StockSpanner(void) {
        std::ios_base::sync_with_stdio(false); 
        std::cin.tie(nullptr); 
        std::cout.tie(nullptr);
        std::cerr.tie(nullptr);
    }
    
    inline int next(const int price) noexcept {
        int ans = 1;
        while (!this->stack.empty() && this->stack.top().second <= price) {
            ans += this->stack.top().first;
            this->stack.pop();
        }
        this->stack.emplace(ans, price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */