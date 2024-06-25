#include<cmath>
#include<vector>
using namespace std;
class Solution {
public:
    int ncr(int n,int r){
        int rr=min(n-r,r);
        double rs=1.0;
        for(int i=0;i<rr;i++){
            rs=rs*(n-i)/(rr-i);
        }
        return round(rs);
    }
    vector<int> getRow(int rowIndex) {
        vector<int> rs(rowIndex+1);
        for(int i=0;i<=rowIndex;i++){
            rs[i]=ncr(rowIndex,i);
        }
        return rs;
    }
};