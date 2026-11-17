class Solution {
public:
    vector<int> runningSum (vector<int>& nums) {
        int n = nums.size() ;
        // vector <int> ans(n);
        int curr_runningSum = 0 ;
        for(int i=0;i<n;i++){
            curr_runningSum += nums[i];
            nums[i] = curr_runningSum ;
        }
        return nums ;
           } 
};