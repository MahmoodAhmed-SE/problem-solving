class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int gain = 0;

        auto processPattern = [&](char first, char second, int value) {
            stack<char> stk;
            string remaining = "";
            for (const char &c : s) {
                if (c == second && !stk.empty() && stk.top() == first) {
                    stk.pop();
                    gain += value;
                } else {
                    stk.push(c);
                }
            }
            while (!stk.empty()) {
                remaining += stk.top();
                stk.pop();
            }
            reverse(remaining.begin(), remaining.end());
            s = remaining;
        };

        if (x > y) {
            processPattern('a', 'b', x);
            processPattern('b', 'a', y);
        } else {
            processPattern('b', 'a', y);
            processPattern('a', 'b', x);
        }

        return gain;
    }
};