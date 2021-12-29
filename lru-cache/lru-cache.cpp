class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {}
    
    int get(int key) {
      if (key_to_node_.count(key) == 0) {
        return -1;
      }
      auto it = key_to_node_[key];
      KeyVal kv = *it;
      linked_list_.erase(it);
      linked_list_.push_front(kv);
      key_to_node_[key] = linked_list_.begin();
      return kv.val;
    }
    
    void put(int key, int value) {
      if (key_to_node_.count(key) == 0) {
        KeyVal kv;
        kv.key = key;
        kv.val = value;
        linked_list_.push_front(kv);
        key_to_node_[key] = linked_list_.begin();
        if (linked_list_.size() > capacity_) {
          KeyVal kv = linked_list_.back();
          key_to_node_.erase(kv.key);
          linked_list_.pop_back();
        }
        return;
      }
      
      auto it = key_to_node_[key];
      KeyVal kv = *it;
      kv.val = value;
      linked_list_.erase(it);
      linked_list_.push_front(kv);
      key_to_node_[key] = linked_list_.begin();
    }
private:
  struct KeyVal {
    int key;
    int val;
  };
  std::list<KeyVal> linked_list_;
  std::unordered_map<int, std::list<KeyVal>::iterator> key_to_node_;
  int capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */