class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if (points.size() <= k) {
            return points;
        }
        TopK(points, k, 0, points.size());
        
        std::vector<std::vector<int>> closest({points.begin(), points.begin() + k});
        return closest;
        
    }
private:
    bool Compare(const std::vector<int>& point1, const std::vector<int>& point2) {
        return point1[0] * point1[0] + point1[1] * point1[1] < 
               point2[0] * point2[0] + point2[1] * point2[1];
    }
    
    void TopK(std::vector<std::vector<int>>& points, int k, int begin, int end) {
        if (begin >= end) {
            return;
        }
        cout << begin << " " << end << endl;
        
        const std::vector<int> pivot = points[begin];
        int left = begin;
        int right = end - 1;
        while (left < right) {
            if (Compare(points[left + 1], pivot)) {
                std::swap(points[left], points[left + 1]);
                left++;
            } else {
                std::swap(points[left + 1], points[right]);
                right--;
            }
        }
        points[left] = pivot;
        // we have [left] number of points < pivot.
        if (left + 1 == k) {
            return;
        }
        
        if (left + 1 < k) {
            TopK(points, k, left + 1, end);
        } else {
            TopK(points, k, begin, left);
        }
        
    }
};