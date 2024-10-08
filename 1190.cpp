class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> stk;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                int start = stk.top();
                stk.pop();

                reverse(s.begin() + start + 1, s.begin() + i);
            }
        }

        string result;
        for (char &c : s) {
            if (c != '(' && c != ')') {
                result += c;
            }
        }

        return result;
    }
};
