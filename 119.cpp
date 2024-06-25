#include<cmath>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> rs(rowIndex+1);
        long long int res=1;
        rs[0]=1;
        for(int i=1;i<=rowIndex;i++){
            res=res*(rowIndex-i+1)/(i);
            rs[i]=res;
        }
        return rs;
    }
};

