class Solution {
public:
    int longestValidParentheses(string s) {
        vector<pair<int, int>> lengths;
        vector<int> seperators;

        stack<int> stk;
        // )()())()()()
        // ()(()

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } 
            else {
                if (!stk.empty()) {
                    lengths.push_back(make_pair(stk.top(), i));
                    stk.pop();
                } else {
                    seperators.push_back(i);
                }
            }
        }

        while (!stk.empty()) {
            seperators.push_back(stk.top());
            stk.pop();
        }

        vector<int> results(s.size());

        if (seperators.size() < 1) {
            for (const auto &p : lengths) {
                results[0]+=2;
            }


            int m = 0;

            for (const int &i : results) {
                m = max(i, m);
            }

            return m;
        }

        sort(seperators.begin(), seperators.end());


        int sepsize = seperators.size();
        for (int i = 0; i < sepsize; ++i) {
            for (const auto &p : lengths) {
                if (i + 1 != sepsize) {
                    if (p.first > seperators[i] && p.second < seperators[i+1]) {
                        results[i] += 2;
                    }
                } else {
                    if (p.first > seperators[i]) {
                        results[i] += 2;
                    }
                }
            }
            
        }

        results.push_back(0);
        for (const auto &p : lengths) {
            if (p.second < seperators[0]) {
                results[results.size()-1] += 2;
            }
        }




        int m = 0;

        for (const int &i : results) {
            m = max(i, m);
        }

        return m;
    }
};