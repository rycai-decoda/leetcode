class BrowserHistory {
public:
    
    BrowserHistory(string homepage) {
        history_.push_back(homepage);
    }
    
    void visit(string url) {
        pos_++;
        if (pos_ <= history_.size() - 1) {
            history_[pos_] = url;
            history_.resize(pos_ + 1);
        } else {
          history_.push_back(url); 
        }
    }
    string back(int steps) {
      pos_ = pos_ >= steps ? pos_ - steps : 0;
      return history_[pos_];
    }
    
    string forward(int steps) {
       pos_ = std::min(steps + pos_, history_.size() - 1);
      return history_[pos_];
    }
private:
  vector<string> history_;
  size_t pos_ = 0;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */