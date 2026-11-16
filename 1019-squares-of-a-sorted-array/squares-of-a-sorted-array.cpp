class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n  = nums.size() ;
        int left =0 ;
        int right = n-1 ;
        int k =n-1;
        vector <int> ans(n);

        while(left <= right) {
            if(abs(nums[right]) > abs(nums[left]) ) {
                ans[k] = nums[right] * nums[right] ;
            k--;
            right--;
            }
            else if(abs(nums[right]) < abs(nums[left]) ) {
                ans[k] = nums[left] * nums[left] ;
                k--;
                left++ ;
            }
            else {
                ans[k] = nums[left] * nums[left] ;
                k--;
                left++;
             
            }
        }

         return ans ;
    }
};