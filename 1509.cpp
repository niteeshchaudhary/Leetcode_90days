#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int ans=INT_MAX;
        sort(nums.begin(),nums.end());
        if(nums.size()<=4){
            return 0;
        }
        for(int i=0;i<=3;i++){
            ans=min(ans,nums[nums.size()+i-4]-nums[i]);
        }
        return ans;
    }
};