// https://leetcode.com/problems/simple-bank-system/

class Bank {
public:
    std::vector<long long> bank;
    const int size = 0;

    Bank(vector<long long> & balance) : size(balance.size()) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        this->bank =* &balance;
    }

    inline const bool is_valid_id(const int & account) const noexcept {
        return account <= this->size;
    }

    inline const bool is_valid_balance(const int & account, const long long & money) const noexcept {
        return this->bank[account-1] >= money;
    }
    
    inline const bool transfer(const int account1, const int account2, const long long money) noexcept {
        if (!this->is_valid_id(account1) || !this->is_valid_id(account2) || !this->is_valid_balance(account1, money)) {
            return false;
        }

        this->bank[account1-1] -= money;
        this->bank[account2-1] += money;

        return true;
    }
    
    inline const bool deposit(const int account, const long long money) noexcept {
        if (!this->is_valid_id(account)) {
            return false;
        }

        this->bank[account-1] += money;

        return true;
    }
    
    inline const bool withdraw(const int account, const long long money) noexcept {
        if (!this->is_valid_id(account) || !this->is_valid_balance(account, money)) {
            return false;
        }

        this->bank[account-1] -= money;

        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */