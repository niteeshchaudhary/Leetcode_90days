#include<queue>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> vc(nums1.size());
        priority_queue<int,vector<int>,greater<int>> pq;
        long long mx=0,sm=0L;
        for(int i=0;i<nums1.size();i++){
            vc[i]=make_pair(nums2[i],nums1[i]);
        }
        sort(vc.rbegin(),vc.rend());

        for(int i=0;i<k;i++){
            pq.push(vc[i].second);
            sm+=vc[i].second;
        }
        mx=1L*sm*vc[k-1].first;
        for(int i=k;i<nums1.size();i++){
            sm-=pq.top();
            pq.pop();
            pq.push(vc[i].second);
            sm+=vc[i].second;
            long long tmp=1L*sm*vc[i].first;
            if(tmp>mx){
                mx=tmp;
            }
        }

        
        return mx;
    }
};
