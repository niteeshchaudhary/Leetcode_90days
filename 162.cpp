#include <vector>
using namespace std;
class Solution {
public:
    int binsearch(vector<int> nums,int l,int r){
        int mid=(l+r)/2;
        if(nums[mid]>nums[mid-1]){
            if(nums[mid]>nums[mid+1]){
                return mid;
            }
            else{
                return binsearch(nums,mid+1,r);
            }
        }
        else{
            return binsearch(nums,l,mid);
        }
    }
    int findPeakElement(vector<int>& nums) {
        
        if(nums.size()==1){
            return 0;
        }
        if(nums[0]>nums[1]){
                return 0;
            }
            if(nums[nums.size()-1]>nums[nums.size()-2]){
                return nums.size()-1;
            }
        return binsearch(nums,0,nums.size()-1);
    }
};