class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total = 0 ;
        for(int i=0;i<n;i++){
            total+=nums[i] ;
        }
        int left_sum =0 ;
     for(int j=0;j<n;j++){
         int right_sum = total - left_sum - nums[j] ;
         if(right_sum==left_sum) {
            return j;
         }
         left_sum+=nums[j] ;
     }
     return -1 ;
    } 
};