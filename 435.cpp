#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int mx=intervals[0][0],cnt=0;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]<mx){
                cnt++;
                mx=min(intervals[i][1],mx);
            }
            else{
                mx=intervals[i][1];
            }
        }
        return cnt;
    }
};