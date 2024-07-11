class Solution {
public:
    bool isPalindrome(string s) {
        const string alphanumeric = "0123456789qwertyuiopasdfghjklzxcvbnm";
        unordered_set<char> an;
        for (const char &c : alphanumeric) {
            an.insert(c);
        }


        int right = s.length();
        int left = 0;
        while (left < right) {
            char l = tolower(s[left]);
            if (an.find(l) == an.end()) {
                ++left;
                continue;
            }

            char r = tolower(s[right]);
            if (an.find(r) == an.end()) {
                --right;
                continue;
            }

            if (l != r) return false;
            ++left;
            --right;
        }

        return true; 
    }
};