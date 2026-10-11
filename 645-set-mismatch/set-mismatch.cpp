class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size();
        vector <int> count(n+1,0);
        for(int x: nums) {
            count[x]++;
        }

int repeated =-1 ;
int missed = -1 ;

        for(int i=0;i<count.size();i++) {
            if(count[i]==2){
                 repeated = i ;
            }
            else if(count[i]==0 && i!=0){
                 missed = i ;
            }
        }
return {repeated,missed};
   
    }
};