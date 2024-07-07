class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        // save each number in a hash table (set)
        unordered_set<int> nums_set(nums.begin(), nums.end());
        
        unordered_map<int, int> consq;

        // iterate over each number, and check (using a while loop) 
        // for a probable consequtive number (by adding one to the current number)
        // and check if it exists in the hash table (set), if so increment the 
        // consequtive count for the said number. 
        for (const int &n : nums_set) {
            // if a number has previous number (in this case already going to be 
            // counted / or will be counted) continue.
            if (nums_set.find(n-1) != nums_set.end()) {
                continue;
            }
            
            consq[n] = 1;
            int x = n + 1;


            for (; nums_set.find(x) != nums_set.end(); ++x) {
                ++consq[n];
            }
        }

        // look for the maximum number from the consequtive number count
        int max = 1;
        for (const auto &p : consq) {
            if (p.second > max) max = p.second;
        }

        return max;
    }
};