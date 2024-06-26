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
        if(j==0){
            return 1;
        }
        int start=0;
        int rot=nums[start],temp=nums[start]-1;
        while(true){
            if(rot==nums[rot-1]){
                start++;
                if(start>=j){
                    break;
                }
                rot=nums[start];
            }
            else if(rot<=j){
                if(rot-1==start+1){
                    start++;
                }
                temp=nums[rot-1];
                nums[rot-1]=rot;
                rot=temp;
            }
            else{
                start++;
                if(start>=j) break;
                rot=nums[start];
            }
        }
        for(int i=0;i<start;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return start+1;
    }
};