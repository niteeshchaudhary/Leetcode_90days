// T:O(log(1))

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles-1)/(numExchange-1);
    }
};

// Or
// T:O(log(n))
// class Solution {
// public:
//     int numWaterBottles(int numBottles, int numExchange) {
//         int ans=numBottles;
//         int q=numBottles,r=-1;
//         while(q>=numExchange){
//             r=q%numExchange;
//             q/=numExchange;
//             ans+=q;
//             q+=r;
//         }
//         return ans;
        
//     }
// };