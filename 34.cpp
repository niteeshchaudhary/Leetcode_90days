#include<vector>
#include<utility>
using namespace std;
class Solution {
public:
    void binsearch(vector<int>& nums, int target,vector<int>& ans,int l,int r,int mode){
        int mid=(l+r)/2;
        if(r<l){
            return;
        }
        if(nums[mid]==target){

            ans[0]=min(mid,ans[0]);
            ans[1]=max(mid,ans[1]);
            if(mid>0 && mode !=1 && nums[mid-1]==target)
                binsearch(nums,target, ans,l,mid-1,-1);
            if(mid<nums.size()-1 && mode!=-1 && nums[mid+1]==target)
                binsearch(nums,target, ans,mid+1,r,1);
        }
        else if(nums[mid]>target){
            binsearch(nums,target, ans,l,mid-1,mode);
        }
        else{
            binsearch(nums,target,ans,mid+1,r,mode);
        }

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1,-1};
        ans[0]=nums.size();
        binsearch(nums,target,ans,0,nums.size()-1,0);
        if(ans[0]>ans[1]){
            return {-1,-1};
        }
        return ans;
    }
};