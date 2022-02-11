class LFUCache {
public:
    struct Node {
      int key;
      int val;
      int count;
    };
    LFUCache(int capacity) : capacity_(capacity) {
      
    }
    
    int get(int key) {
      
      std::cout << "get " << key << std::endl;
      if (key_to_node_.count(key) == 0) {
        return -1;
      }
      
      auto it = key_to_node_[key];
      int val = it->val;
      
      Node updated(*it);
      
      freq_to_list_[it->count].erase(it);
      
      if (freq_to_list_[updated.count].empty()) {
        if (updated.count == min_freq_) {
          min_freq_++;
        }
        
      }
      
      updated.count++;
      freq_to_list_[updated.count].push_front(updated);
      key_to_node_[key] = freq_to_list_[updated.count].begin();
      
      return val;
    }
    
    void put(int key, int value) {
      
      if (capacity_ == 0) {
        return;
      }
      
      std::cout << "put " << key << std::endl;
      if (key_to_node_.count(key) != 0) {
        key_to_node_[key]->val = value;
        
        get(key);
        return;
      }
      
      if (key_to_node_.size() == capacity_) {
        auto node = freq_to_list_[min_freq_].back();
        key_to_node_.erase(node.key);
        freq_to_list_[min_freq_].pop_back();
      }
      
      Node node;
      node.key = key;
      node.val = value;
      node.count = 1;
      
      freq_to_list_[1].push_front(node);
      key_to_node_[key] = freq_to_list_[1].begin();
      min_freq_ = 1;
      
    }
  
private:
  int capacity_;
  
  // sorted by count and recent used.
  std::list<Node> list_;
  std::unordered_map<int, std::list<Node>::iterator> key_to_node_;
  
  // each list is sorted by new -> old
  std::unordered_map<int, std::list<Node>> freq_to_list_;
  
  int min_freq_;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */