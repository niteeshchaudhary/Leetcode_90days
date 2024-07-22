#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> vp(heights.size());
        vector<string> ans;
        for(int i=heights.size()-1;i>-1;i--){
            vp[i]={heights[i],names[i]};
        }
        sort(vp.begin(),vp.end());
        for(int i=heights.size()-1;i>-1;i--){
            ans.push_back(vp[i].second);
        }
        return ans;
        
    }
};