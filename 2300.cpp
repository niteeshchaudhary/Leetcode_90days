#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int binsearch(vector<int>& potions,double suc,int l,int r){
        int mid=(r+l)/2;
        if(potions[mid]>=suc){
            if (l==r)
            {
                return l;
            }
           return binsearch(potions,suc,l,mid);
        }
        else{
            if (l==r)
            {
                return -l;
            }
            return binsearch(potions,suc,mid+1,r);
        }

    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int cnt=0;
        vector<int> ans(spells.size());
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            cnt=0;
            int ind=binsearch(potions,1.0*success/spells[i],0,potions.size()-1);
            if(ind<0){
                cnt=potions.size()-abs(ind)-1;
            }
            else{
                cnt=potions.size()-ind;
            }
            ans[i]=cnt;
        }
        return ans;
    }
};