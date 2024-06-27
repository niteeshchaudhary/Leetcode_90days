class Solution {
public:
    int hammingWeight(int n) {
        bitset<32> b1(n);
        return b1.count();
    }
};