#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> arr(26,0);
        int steps=0;
        for(int i=0;i<word.size();i++){
            arr[word[i]-97]++;
        }
        sort(arr.begin(),arr.end(),greater<int>());
        for(int i=0;i<26;i++){
            if(arr[i]>0){
                steps+=arr[i]*(i/8+1);
            }
            else{
                break;
            }
        }
        return steps;
    }
};