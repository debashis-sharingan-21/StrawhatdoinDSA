
class Solution {
public:
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0;
        string ans = "";

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int len = j - i + 1;

                if (len > maxLen && isPalindrome(s, i, j)) {
                    maxLen = len;
                    ans = s.substr(i, len);
                }
            }
        }

        return ans;
    }
};
