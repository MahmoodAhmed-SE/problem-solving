class KthLargest {
private:
	vector<int> heap;
	int k;
public:

	KthLargest(int k, vector<int>& nums) : k(k) {
		for (const int &n : nums) {
			if (heap.size() < k) {
				insert(n);
			} else {
				if (n > heap[0]) {
					pop();
					insert(n);
				}
			}

		}
	}	

	void siftUp(int node) {
		int parent = (node - 1) / 2;
		while (parent >= 0 && heap[node] < heap[parent]) {
			swap(heap[parent], heap[node]);

			node = parent;
			parent = (node - 1) / 2;
		}
	}

	void insert(int val) {
		heap.push_back(val);
		siftUp(heap.size() - 1);
	}

	void pop() {
		if (heap.size() > 1) {
			swap(heap[0], heap[heap.size() - 1]);
			heap.pop_back();

			// sift down operation:
			int index = 0; 
			int left = index * 2 + 1;
			int right = index * 2 + 2;

			while (left < heap.size()) {
				if (right >= heap.size() || heap[left] < heap[index]) {
					swap(heap[index], heap[left]);
					index = left;
				} else if (right < heap.size() && heap[right] < heap[index]) {
					swap(heap[index], heap[right]);
					index = right;
				} else break;
				
				int left = index * 2 + 1;
				int right = index * 2 + 2;
			}
		} else {
			heap.pop_back();
		}
	}

	int add(int val) {
		if (heap.size() < k) {
			insert(val);
			return heap[0];
		}
		if (val > heap[0]) {
			pop();
			insert(val);
			return heap[0];
		}

		return heap[0];

	}
};

class KthLargest {
private:
    vector<int> heap;
    int k;

    void siftUp(int node) {
        int parent = (node - 1) / 2;
        while (node > 0 && heap[node] < heap[parent]) {
            swap(heap[parent], heap[node]);
            node = parent;
            parent = (node - 1) / 2;
        }
    }

    void siftDown(int node) {
        int left = 2 * node + 1;
        int right = 2 * node + 2;
        int smallest = node;

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != node) {
            swap(heap[node], heap[smallest]);
            siftDown(smallest);
        }
    }

    void insert(int val) {
        heap.push_back(val);
        siftUp(heap.size() - 1);
    }

    void pop() {
        if (!heap.empty()) {
            heap[0] = heap.back();
            heap.pop_back();
            siftDown(0);
        }
    }

public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (const int &n : nums) {
            if (heap.size() < k) {
                insert(n);
            } else if (n > heap[0]) {
                pop();
                insert(n);
            }
        }
    }

    int add(int val) {
        if (heap.size() < k) {
            insert(val);
        } else if (val > heap[0]) {
            pop();
            insert(val);
        }
        return heap[0];
    }
};
