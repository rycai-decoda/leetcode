class Solution {
public:
    int function_id(const string& log) {
        return std::stoi(log.substr(0, log.find(':')));
    }
    bool is_start(const string& log) {
        size_t first_colon = log.find(':');
        size_t last_colon = log.find(':', first_colon + 1);
        
        return 0 == log.compare(first_colon + 1, last_colon - first_colon - 1, "start");
    }
    int timestamp(const string& log) {
        size_t last_colon = log.rfind(':');
        return std::stoi(log.substr(last_colon + 1));
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        
        // Sorts by timestamp.
        std::sort(logs.begin(), logs.end(), [this](const string& l1, const string& l2) {
            int t1 = timestamp(l1);
            int t2 = timestamp(l2);
            
            if (t1 != t2) {
                return t1 < t2;
            }
            
            // start
            return is_start(l1);
        });
        
        int max_function_id = 0;
        for (const string& log : logs) {
            max_function_id = std::max(max_function_id, function_id(log));
        }
        
        std::stack<int> function_ids;
        std::vector<int> last_start_t(max_function_id + 1, 0);
        std::vector<int> duration(max_function_id + 1, 0);
        for (const string& log : logs) {
            int id = function_id(log);
            int t = timestamp(log);
            if (is_start(log)) {
                if (!function_ids.empty()) {
                    int prev_func = function_ids.top();
                    duration[prev_func] += t - last_start_t[prev_func];
                }
                function_ids.push(id);
                last_start_t[id] = t;
            } else {
                duration[id] += t - last_start_t[id] + 1;
                function_ids.pop();
                
                if (!function_ids.empty()) {
                    int prev_func = function_ids.top();
                    last_start_t[prev_func] = t + 1;
                }
            }
        }
        return duration;
    }
};