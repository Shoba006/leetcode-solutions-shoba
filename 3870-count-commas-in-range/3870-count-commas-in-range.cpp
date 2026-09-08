class Solution {
public:
    int countCommas(int n) {
        long long ans = 0;
        
        for (long long start = 1000; start <= n; start *= 1000) {
            ans += n - start + 1;
        }
        
        return ans;
    }
};