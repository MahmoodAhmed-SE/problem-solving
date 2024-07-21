class Solution {


public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<short, vector<short>> heap(stones.begin(), stones.end());

        while (heap.size() > 1) {
            short heaviest = heap.top();
            heap.pop();
            short second_heaviest = heap.top();
            heap.pop();

            if (heaviest != second_heaviest) {
                heap.push(heaviest - second_heaviest);
            }
        }

        return heap.size() == 0 ? 0 : heap.top();
    }
};