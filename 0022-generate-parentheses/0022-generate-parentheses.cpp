class Solution {
public:
    vector<string> ans;

    void solve(int open, int close, string s) {
        if (open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }
        if (open > 0) {
            solve(open - 1, close, s + "(");
        }
        if (close > open) {
            solve(open, close - 1, s + ")");
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(n, n, "");
        return ans;
    }
};