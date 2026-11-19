class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0 , heighest_alti = 0 ;
        for(int x :gain) {
            altitude += x ;
            heighest_alti = max(heighest_alti,altitude) ;
        }
        return heighest_alti;
    }
};