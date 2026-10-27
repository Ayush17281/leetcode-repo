class Solution {
public:
    vector<string>createGrid(int m, int n) {
        vector<string> temp(m,string(n,'#')) ;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==n-1 ) {
                    temp[i][j]= '.' ;
                }
            }
        }
        return temp ;
    }
};