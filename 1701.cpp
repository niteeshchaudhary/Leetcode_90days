#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currtime=customers[0][0];
        double atime=0.0;
        for(int i=0;i<customers.size();i++){
            if(customers[i][0]<=currtime){
                currtime+=customers[i][1];
                atime+=currtime-customers[i][0];
            }
            else{
                currtime=customers[i][0]+customers[i][1];
                atime+=customers[i][1];
            }
        }
        return atime/customers.size();
    }
};