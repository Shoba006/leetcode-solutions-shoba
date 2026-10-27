class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int st = nums[0];
        int maxi = nums[0];
        for(int i =1; i<nums.size(); i++){
            st = max(nums[i], nums[i]+st);
            maxi = max(st,maxi);
        }
        return maxi;
    }
};