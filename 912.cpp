#include<utility>
#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int> nm;
        for(int i=0;i<nums.size();i++){
            nm.push(nums[i]);
        }
        for(int i=nums.size()-1;i>-1;i--){
            nums[i]=nm.top();
            nm.pop();
        }
        return nums;
    }
};