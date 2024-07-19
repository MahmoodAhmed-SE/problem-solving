class Solution {
public:
    auto comparator = [](const pair<int, int> &a, const pair<int,int> &b) {
        return a.second < b.second;
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (const int &n : nums) {
            ++m[n];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (const auto &p : m) {
            pq.push(p);
        }

        vector<int> results;
        for (int i = 0; i < k; ++i) {
            if (pq.empty) break;
            results.push(pq.top());
            pq.pop();
        }
        return results;
    }
};