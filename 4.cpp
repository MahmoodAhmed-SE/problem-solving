class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // nums1:   1, 2, 3, 4, 5, 6
        // nums2:   2, 6, 7, 10
        // sorted: 1, 2, 2 ,3 ,4, 5, 6, 6, 7, 10
        // median: (4 + 5) / 2
        
        /*
        - get the size of both
        - we iterate with both arrays as in one go, and take the least element (node) of both arrays
        - we reach the half of the size and return the last array element (if it was odd)
        */

        int n1size = nums1.size();
        int n2size = nums2.size();
        int size_of_nums = n1size + n2size;
        
        bool is_odd = size_of_nums % 2 == 1;
        
        int iteration = 0;
        int max_iterations = size_of_nums / 2;

        vector<int> half;

        // for swapping turns
        bool turn = true;

        int n1 = 0;
        int n2 = 0;
        while (iteration <= max_iterations) {
            if (turn) {
                turn = false;
                if (n1 < n1size) {
                    if (n2 == n2size) {
                        half.push_back(nums1[n1]);
                        ++n1;
                        ++iteration;
                        continue;
                    }

                    if (nums1[n1] <= nums2[n2]) {
                        half.push_back(nums1[n1]);
                        ++n1;
                        ++iteration;
                    }
                }
            }
            else {
                turn = true;
                if (n2 < n2size) {
                    if (n1 == n1size) {
                        half.push_back(nums2[n2]);
                        ++n2;
                        ++iteration;
                        continue;
                    }

                    if (nums2[n2] <= nums1[n1]) {
                        half.push_back(nums2[n2]);
                        ++n2;
                        ++iteration;
                    }
                }
            }
        }      

        
        if (is_odd) {
            return half[half.size() - 1];
        } 
        else {
            return double(half[half.size() - 1] + half[half.size() - 2]) / 2;
        }
    }
};