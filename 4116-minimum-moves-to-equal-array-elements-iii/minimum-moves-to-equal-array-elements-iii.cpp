class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size() ;
        int max_ele = INT_MIN ; 
        for(int i = 0 ;i<n;i++) {
            max_ele = max(nums[i], max_ele);
        }

        int ans = 0 ;
        int res ;
        for(int i=0;i<n;i++) {
            if(nums[i] < max_ele) {
                res= max_ele - nums[i];
                ans += res ;
            }
        }
return ans ;
    }
};