class Solution {
public:
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    bool check(const string& a, const string& b) {
        int n = a.size();
        int l = 0, r = n - 1;

        while (l < r && a[l] == b[r]) {
            l++;
            r--;
        }

        return isPalindrome(a, l, r) ||
               isPalindrome(b, l, r);
    }

    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }
};