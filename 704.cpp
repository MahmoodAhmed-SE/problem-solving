class Solution {
public:
    int search(vector<int>& nums, int target) {
        short left = 0; 
        short right = nums.size() - 1;


        while (left <= right) {
            short mid = (left + right + 1) / 2;
            if (target == nums[mid]) return mid;
            else if (target < nums[mid]) {
                --right;
            } else {
                ++left;
            }
        }

        return -1;
    }
};