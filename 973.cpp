class Compare {
    public: 
    bool operator()(const pair<vector<int>, double> &a, const pair<vector<int>, double> &b) {
        return a.second < b.second;
    };
};

class Solution {
private: 

double getDistance(const vector<int> &p) {
    return sqrt(pow(p[0], 2) + pow(p[1], 2));
}

public:

    // pair<point, distance>
    priority_queue<pair<vector<int>, double>, vector<pair<vector<int>, double>>, Compare> minHeap;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for (const vector<int> &p : points) {
            double distance = getDistance(p);

            if (minHeap.size() < k) {
                minHeap.push(make_pair(p, distance));
            } else {
                if (distance < minHeap.top().second) {
                    minHeap.pop();
                    minHeap.push(make_pair(p, distance));
                }
            }
        }

        vector<vector<int>> result;

        while (!minHeap.empty()) {
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }

        return result;
    }
};