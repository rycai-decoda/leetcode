class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {
        
    }
    
    int get(int key) {
        if (map_.count(key) == 0) {
            return -1;
        }
        
        auto it = map_[key];
        int val = it->val;
        
        list_.push_front(*it);
        map_[key] = list_.begin();
        list_.erase(it);
        return val;
    }
    
    void put(int key, int value) {
        if (map_.count(key) != 0) {
            auto it = map_[key];
            list_.erase(it);
        }
        
        KeyVal kv;
        kv.key = key;
        kv.val = value;
        list_.push_front(kv);
        map_[key] = list_.begin();
        
        if (list_.size() > capacity_) {
            map_.erase(list_.back().key);
            list_.pop_back();
        }
    }

private:
    struct KeyVal {
        int key;
        int val;
    };
    uint capacity_;
    std::list<KeyVal> list_;
    std::unordered_map<int, std::list<KeyVal>::iterator> map_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */