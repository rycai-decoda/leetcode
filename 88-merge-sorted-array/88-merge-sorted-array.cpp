class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = m - 1;
        int i2 = n - 1;
        int i = m + n - 1;
        
        while (i >= 0) {
            
            if (i1 < 0) {
                nums1[i] = nums2[i2];
                i--;
                i2--;
                continue;
            }
            if (i2 < 0) {
                break;
            }
            
            if (nums1[i1] < nums2[i2]) {
                nums1[i] = nums2[i2];
                i--;
                i2--;
                continue;
            }
            
            // nums1[i1] > nums2[i2]
            nums1[i] = nums1[i1];
            i--;
            i1--;
        }
        
        
    }
};