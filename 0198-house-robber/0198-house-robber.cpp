class Solution {
public:
    int dp[101];
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return abc(0,n,nums);
    }
    int abc (int i, int n,vector<int>& nums){
        //base
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];
        //rec
        int p = nums[i]+ abc(i+2, n, nums);
        int s = abc(i+1,n,nums);
        return dp[i] = max(p, s);
    }
};