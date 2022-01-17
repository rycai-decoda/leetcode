class MovingAverage {
public:
    MovingAverage(int size) : size_(size) {
        
    }
    
    double next(int val) {
        sum_ += val;
        window_.push_back(val);
        if (window_.size() > size_) {
            sum_ -= window_.front();
            window_.pop_front();
        }
        
        return (double) sum_ / (double) window_.size();
    }
    
private:
    int size_;
    int sum_ = 0;
    std::list<int> window_;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */