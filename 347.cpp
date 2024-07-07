class Solution {
public:
    vector<int> insertion_sort(unordered_map<int, int> mp) {
        vector<int> nums;
        vector<int> freq;
        for (const auto &p : mp) {
            nums.push_back(p.first);
            freq.push_back(p.second);
        }
        
        for(int i = 1; i < nums.size(); i++) {
            int k = i;
            while(k > 0 && freq[k] < freq[k-1]) {
                swap(nums[k], nums[k-1]);
                swap(freq[k], freq[k-1]);
                --k;
            }
        }
        return nums;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (const int &num : nums) {
            ++freq[num];
        }

        vector<int> sortedRes = insertion_sort(freq);
        vector<int> res;
        int last = sortedRes.size() - 1;
        for (int i = last; i > last - k; --i) {
            res.push_back(sortedRes[i]);
        }

        return res;
    }
};
