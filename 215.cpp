// using modified heapsort algorithm (maxheap)
// class Solution {
// public:
//     priority_queue<int> heap;

//     int findKthLargest(vector<int>& nums, int k) {
//         for (const int &n : nums) {
//             heap.push(n);
//         }

//         for (int i = 1; i < k; ++i) {
//             heap.pop();
//         }
        
//         return heap.top();
//     }
// };


// Efficient min heap to problem scenario case:
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        
        for (const int &n : nums) {
            if (heap.size() < k) {
                heap.push(n);
            } else {
                if (n > heap.top()) {
                    heap.pop();
                    heap.push(n);
                }
            }
        }

        return heap.top();
    }
};