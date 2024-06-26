#include<vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0 && nums[i]<=nums.size()){
                nums[j]=nums[i];
                j++;
            }
        }
        for(int i=0;i<j;i++){
           int ind=abs(nums[i])-1;
           nums[ind]=abs(nums[ind])*-1;
        }
        for(int i=0;i<j;i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return j+1;
    }
};