class KthLargest {
private:
priority_queue<int, vector<int>, greater<int>> heap;
int k;

public:

    KthLargest(int k, vector<int>& nums) : k(k) {
        for (const int &n : nums) {
            add(n);
        }
    }
    
    int add(int val) {
        if (heap.size() < k) {
            heap.push(val);
            return heap.top();
        } else {
            if (heap.top() < val) {
                heap.pop();
                heap.push(val);
            }
        }
        
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */