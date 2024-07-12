class Solution {
public:    
    struct Node {
        int number;
        Node* right;

        Node(int data) : number(data), right(nullptr) {}
    };

    int findTheWinner(int n, int k) {
        if (n == 1) return 1;


        Node* root = new Node(1);
        Node* prev = root;

        for (int i = 2; i <= n; ++i) {
            Node* newNode = new Node(i);
            prev->right = newNode;
            prev = newNode;
        }
        prev->right = root;  
        
        Node* curr = root;
        Node* last = prev;

        while (curr->right != curr) {
            for (int i = 1; i < k; ++i) {
                last = curr;
                curr = curr->right;
            }

            last->right = curr->right;
            delete curr;
            curr = last->right;
        }

        int winner = curr->number;
        delete curr;
        return winner;
    }
};