#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        visited.insert(n);
        while(n!=1){
            int temp=n;
            n=0;
            while(temp!=0){
                n+=(temp%10)*(temp%10);
                temp/=10;
            }
            if(visited.count(n)){
                return false;
            }
            visited.insert(n);

        }
        return true;
        
    }
};