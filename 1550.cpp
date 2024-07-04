#include<vector>
using namespace std;
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int od=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]&1){
                od++;
                if(od==3){
                    return true;
                }
            }
            else{
                od=0;
            }
        }
        return false;
        
    }
};