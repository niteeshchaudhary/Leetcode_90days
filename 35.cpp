#include<vector>
using namespace std;
class Solution {
public:
    int binsearch(vector<int>& nums, int target,int l,int r){
        int m=(l+r)/2;
        if(l==r){
            if(nums[m]<target)
                return l+1;
            return l;
        }
        if(nums[m]==target){
            return m;
        }
        else if(nums[m]>target){
            return binsearch(nums,  target, l, m);
        }

        return binsearch(nums,  target, m+1, r);

    } 
    int searchInsert(vector<int>& nums, int target) {
        return binsearch(nums,target,0,nums.size()-1);
    }
};