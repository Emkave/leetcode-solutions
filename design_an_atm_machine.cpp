// https://leetcode.com/problems/design-an-atm-machine/

class ATM {
public:
    std::vector<long long> atm;
    const std::map<int, int> m = {
        {0, 20},
        {1, 50},
        {2, 100},
        {3, 200},
        {4, 500}
    };

    inline const long long min(const long long & a, const long long & b) const noexcept {
        return (a < b) ? a : b;
    }

    ATM() {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);

        this->atm = std::vector<long long>(5, 0);
    }
    
    inline void deposit(const vector<int> banknotesCount) noexcept {
        for (unsigned short i=0; i<5; i++) {
            this->atm[i] += banknotesCount[i];
        }
    }
    
    inline vector<int> withdraw(long long amount) noexcept {
        std::vector<int> wt (5, 0);
        for (short i=4; i>=0; i--) {
            const long long n2 = this->m.at(i);
            const long long n1 = amount / n2;
            amount -= min(n1, this->atm[i]) * n2;
            wt[i] += min(n1, this->atm[i]);
        }

        if (amount == 0) {
            for (unsigned short i=0; i<5; i++) {
                this->atm[i] -= wt[i];
            }
            return wt;
        } else {
            return std::vector<int>{-1};
        }
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */