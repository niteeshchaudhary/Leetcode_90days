#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

bool custom(const pair<int,int>& p1, const pair<int,int>& p2){
    return p1.first < p2.first;
}

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> vp;
        for(int i=0;i<nums.size();i++){
            int k=nums[i],nw=0,p=1;
            if(k==0){
                nw=mapping[0];
            }
            else{
                while(k){
                    nw=nw+mapping[k%10]*p;
                    k=k/10;
                    p*=10;
                }
            }
            vp.push_back({nw,nums[i]});
        }
        sort(vp.begin(),vp.end(),custom);
        for(int i=0;i<nums.size();i++){
            nums[i]=vp[i].second;
        }
        return nums;
    }
};