class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        unordered_map<char, int> tasksMap;

        for (const char &t : tasks) {
            ++tasksMap[t];
        }

        string seq = "QWERTYUIOPASDFGHJKLZXCVBNM";

        unordered_map<char, int> tasksMapClone(tasksMap);
        for (int i = 0; i < seq.length(); ++i) {
            while(!tasksMapClone.empty()) {
                if (tasks[i] )
            }
        }
    }
};