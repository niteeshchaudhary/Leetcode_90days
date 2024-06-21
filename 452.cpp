#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int mx=INT_MIN,cnt=0;
        for(int i=0;i<points.size();i++){
            if(points[i][0]<=mx){
                mx=min(points[i][1],mx);
            }
            else{
                cnt++;
                mx=points[i][1];
            }
        }
        return points.size();
    }
};