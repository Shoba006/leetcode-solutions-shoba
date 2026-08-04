class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());

        int start = nums[0];
        int end = nums[nums.size()-1];
        int i = 0;

        while(start<=end){
            if(i<nums.size() && nums[i]==start){
                start++;
                i++;
            }else{
                ans.push_back(start);
                start++;
            }
        }
        return ans;
    }
};