class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        int n=nums.size();

        for(int i=0; i<nums.size(); i++){
            if(nums[i]>mx){
                mx=nums[i];
            }
            if(nums[i]<mn){
                mn=nums[i];
            }
        }
        int mx_ind=0;
        int mn_ind=0;
        for(int i=0; i<nums.size(); i++){
            if(mn==nums[i]){
                mn_ind=i;
            }
            if(mx==nums[i]){
                mx_ind=i;
            }
        }
        int left= max(mn_ind, mx_ind)+1;
        int right= n - min(mn_ind, mx_ind);
        int both = min(mn_ind, mx_ind)+1+n- max(mn_ind, mx_ind);
        int ans = min({left, right, both });
        return ans;
    }
};