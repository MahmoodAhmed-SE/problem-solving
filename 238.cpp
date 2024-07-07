class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> rev;
        for (const int &num : nums) rev.push_back(num);
        int nums_size = nums.size();
        int l = 1; 
        int r = nums_size - 2;
        while (l < nums_size) {
            nums[l] = nums[l - 1] * nums[l]; 
            rev[r] = rev[r + 1] * rev[r];

            ++l; 
            --r;
        }
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                if (rev[i + 1] == 0) {
                    res.push_back(0);
                    continue;
                }
                res.push_back(rev[i+1]);
                continue;
            }

            if (i == nums_size-1) {
                if (nums[i - 1] == 0) {
                    res.push_back(0);
                    continue;
                } 
                res.push_back(nums[i-1]);
                continue;
            }
            
            int val;

            if (i > 0) {
                if (nums[i - 1] == 0) {
                    res.push_back(0);
                    continue;
                } 
                val = nums[i - 1];
            }
            if (i < nums_size-1) {
                if (rev[i + 1] == 0) {
                    res.push_back(0);
                    continue;
                } 
                val *= rev[i + 1];
            }

                  
            res.push_back(val);
        } 

        return res;
    }
};