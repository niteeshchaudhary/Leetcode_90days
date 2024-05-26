#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int arr[4]={0,0,nums[0],nums[1]};
        for(int i=2;i<n;i++){
            arr[0]=arr[1];
            arr[1]=arr[2];
            arr[2]=arr[3];
            arr[3]=max(nums[i]+arr[1],nums[i]+arr[0]);
        }
        return max(arr[3],arr[2]);
    }
};