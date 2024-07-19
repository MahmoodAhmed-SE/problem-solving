#include <bits/stdc++.h>

using namespace std;



class MinHeap {
    private:

    int heapSize;
    int maxSize;
    int *arr;


    public:

    MinHeap(int maxSize) : heapSize(0), maxSize(maxSize) {
       arr = new int[maxSize];
    };

    ~MinHeap() {
        delete[] arr;
    }

    void insert(int data) {
        if (heapSize < maxSize) {
            arr[heapSize] = data;
            siftUp(heapSize);

            ++heapSize;
        } 
        else throw logic_error("heap overflow");
    }

    int extractMin() {
        if (heapSize > 0) {
            int min = arr[0];
            arr[0] = arr[heapSize - 1];
            --heapSize;

            siftDown(0);
            
            return min;
        } else if (heapSize == 0) {
            throw logic_error("can't extract min. heap is empty.");
        }        
    }

    bool isEmpty() {
        return heapSize == 0;
    }

    int getMin() {
        if (heapSize != 0) return arr[0];
        else throw logic_error("can't get min. heap is empty.");
    }


    void siftUp(int i) {
        int parent = (i - 1) / 2;
        while (parent >= 0 && arr[i] < arr[parent]) {
            int temp = arr[i];

            arr[i] = arr[parent];
            arr[parent] = temp;

            i = parent;
            parent = (i - 1) / 2;
        }
    }


    void siftDown(int i) {
        int leftChild = i*2 + 1;
        int rightChild = i*2 + 2;

        
        while ((leftChild < heapSize && arr[leftChild] < arr[i]) || 
        ((rightChild < heapSize && arr[rightChild] < arr[i]))) {
            int lowest;
            if (rightChild < heapSize && arr[rightChild] < arr[leftChild]) {
                lowest = rightChild;
            } else {
                lowest = leftChild;
            }
            
            int temp = arr[i];
            arr[i] = arr[lowest];
            arr[lowest] = temp;

            i = lowest;
            leftChild = i*2 + 1;
            rightChild = i*2 + 2;
        }
    }


    void printArr() {
        cout << endl << "(";
        for (int i = 0; i < heapSize; ++i) {
            if (i < heapSize - 1) cout << arr[i] << ", ";
            else cout << arr[i]; 
        }
        cout << ")" << endl;
    }
};



int main () {
    MinHeap *heap = new MinHeap(20);

    // Hardcoded random numbers for testing
    int testData[] = {5, 3, 8, 1, 9, 2, 7, 4, 6, 0};

    for (int i = 0; i < 10; ++i) {
        heap->insert(testData[i]);
    }


    heap->printArr();
    int min = heap->extractMin();
    cout << "extracted min: " << min; 
    
    heap->printArr();

    delete heap;
    
    

    return 0;
}