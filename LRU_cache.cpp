/*
https://leetcode.com/problems/lru-cache/
*/

class LRUCache {
public:
    std::unordered_map<int, int> mp;
    std::deque<int> cache;
    const size_t size = 0;

    explicit LRUCache(int capacity) : size(capacity) {
        this->mp.reserve(static_cast<size_t>(capacity));
    }
    
    inline int get(int key) const noexcept {
        auto iter = this->mp.find(key);
        if (iter == this->mp.end()) {
            return -1;
        }
        return iter->second;
    }
    
    inline void put(int key, int value) noexcept {
        if (this->cache.size() >= this->size) {
            this->mp[this->cache[this->size-1]] = -1;   
            this->cache.pop_back();
        }

        this->mp[key] = value;
        this->cache.emplace_front(this->mp.find(key)->first);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */