#include<vector>
using namespace std;
// 33. Search in Rotated Sorted Array
class Solution {
public:
    int binsearch(vector<int>& nums, int target,int l,int r){
        int m=(l+r)/2;
        if(nums[m]==target){
            return m;
        }
        if(l==r){
            return -1;
        }
        if(nums[l]>target  && ((target<nums[m] && nums[l]<=nums[m])||target>nums[m])){
            return  binsearch(nums,target, m+1,r);
        }
        else if(nums[l]<target  && target>nums[m]  && nums[l]<=nums[m]){
            return  binsearch(nums,target, m+1,r);
        }
        
        return  binsearch(nums,target, l,m);

    }
    int search(vector<int>& nums, int target) {
      return  binsearch(nums, target, 0,nums.size()-1);
    }
};