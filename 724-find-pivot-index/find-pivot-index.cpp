class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total = 0 ;
        for(int i=0;i<n;i++){
            total+=nums[i] ;
        }
     for(int j=0;j<n;j++){
        int left_sum =0 ;
        for(int k = 0 ;k<j;k++){
            left_sum+=nums[k]; 
        }
         int right_sum = total - left_sum - nums[j] ;
         if(right_sum==left_sum) {
            return j;
         }
     }
     return -1 ;
    } 
};