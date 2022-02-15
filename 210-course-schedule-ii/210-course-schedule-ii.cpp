class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      // incoming[n] nodes -> n
      std::unordered_map<int, std::unordered_set<int>> incoming;
      // outgoing[n] nodes <- n
      std::unordered_map<int, std::unordered_set<int>> outgoing;
      
      
      for (const auto& p : prerequisites) {
        // p[1] -> p[0]
        outgoing[p[1]].insert(p[0]);
        incoming[p[0]].insert(p[1]);
      }
      
      
      std::queue<int> free_nodes;
      for (int c = 0; c < numCourses; c++) {
        if (incoming.count(c) == 0) {
          free_nodes.push(c);
        }
      }
      
      std::vector<int> order;
      while (!free_nodes.empty()) {
        int node = free_nodes.front();
        free_nodes.pop();
        order.push_back(node);
        
        for (int child : outgoing[node]) {
          incoming[child].erase(node);
          // new free node
          if (incoming[child].empty()) {
            free_nodes.push(child);
            incoming.erase(child);
          }
        }
      }
      
      if (order.size() == numCourses) {
        return order;
      }
      
      return {};
    }
};