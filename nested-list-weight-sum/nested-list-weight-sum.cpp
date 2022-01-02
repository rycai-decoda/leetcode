/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        std::unordered_map<int, int> depth;
        int sum = 0;
        RecursivelyFindDepth(nestedList, 1, &sum);
        
        
        // Sum(nestedList, depth, &sum);
        
        return sum;
        
    }
private:
    void Sum(const std::vector<NestedInteger>& list, const std::unordered_map<int, int>& depth, int* sum) {
        for (const NestedInteger& nested : list) {
            if (nested.isInteger()) {
                *sum += depth.at(nested.getInteger()) * nested.getInteger();
            } else {
                Sum(nested.getList(), depth, sum);
            }
        }
        
    }
    
    void RecursivelyFindDepth(const std::vector<NestedInteger>& list, int current_depth, int* sum) {
        std::unordered_set<int> this_list;
        for (const NestedInteger& nested : list) {
            if (nested.isInteger()) {
                *sum += current_depth * nested.getInteger();
            } else {
                RecursivelyFindDepth(nested.getList(), current_depth + 1, sum);
            }
            
        }
        
        // for (int n : this_list) {
        //     (*depth)[n]++;
        // }
    }
};