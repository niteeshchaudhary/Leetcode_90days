#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

bool custom(const pair<int,int> & p1, const pair<int,int> & p2){
    if(p1.first==p2.first){
        return p1.second>p2.second;
    }
    return p1.first<p2.first;
}
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int arr[201];
        int k=0;
        vector<int> ans(nums.size());
        vector<pair<int,int>> vp;
        for(int i=0;i<nums.size();i++){
            arr[nums[i]+100]++;
        }
        for(int i=0,j=0;i<=200;i++){
            if(arr[i]>0){
                vp.push_back({arr[i],i-100});
                j++;
            }
        }
        sort(vp.begin(),vp.end(),custom);
        for(int i=0;i<vp.size();i++){
            for(int j=0;j<vp[i].first;j++){
                ans[k]=vp[i].second;
                k++;
            }
        }
        return ans;
    }
};