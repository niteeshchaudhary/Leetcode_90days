#include<vector>
using namespace std;   

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mn=piles[0],mx=piles[0];
        for(int i=1;i<piles.size();i++){
            mn=min(mn,piles[i]);
            mx=max(mx,piles[i]);
        }
        int l=1,r=mx;
        while(true){
            if(l==r){
                return l;
            }
            int mid=(l+r)/2,cnt=0;
            for(int i=0;i<piles.size();i++){
                cnt+=ceil(piles[i]*1.0/mid);
            }

            if(cnt>h){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
    }
};