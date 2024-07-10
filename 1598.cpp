#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt=0;
        for(int i=0;i<logs.size();i++){
            if(logs[i][0]!='.'){
                cnt++;
            }
            else if(logs[i][1]=='.' && cnt>0){
                cnt--;
            }
        }
        return cnt;
        
    }
};