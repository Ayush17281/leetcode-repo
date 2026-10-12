class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        // //Brut Force Approach 
        // int n = numbers.size();
        // int idx1 = -1;
        // int idx2 = -1;
        // for(int i=0;i<n;i++) {
        //     for(int j=i+1;j<n;j++){
        //         if(numbers[i]+numbers[j] == target){
        //             idx1 = i+1 ;
        //             idx2 = j+1 ;
        //             break ;
        //         }
        //     }
        //         if(idx1 != -1 ) {break ;}
        // }

        // return {idx1,idx2} ;

    // Optimised Approach 
    int n = numbers.size();
    int start = 0 ;
    int end = n-1 ;
    int idx1 = -1;
    int idx2 = -1 ;
    while(start<end) {
        int res = numbers[start]+numbers[end] ;
        if(res == target) {
            idx1 = start+1;
            idx2 = end+1;
            break;
        }  
        else if(res>target) {
            end-- ;
        }
        else{
            start++;
        }
    }

return {idx1 , idx2};

}
};