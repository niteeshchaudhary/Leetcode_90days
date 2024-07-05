#include<vector>
#include<climits>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp=head;
        int mn=INT_MAX,mx=0,i=0,j=-1;
        vector<int> ans={-1,-1};
        while(temp->next->next){
            if((temp->val>temp->next->val && temp->next->next->val>temp->next->val)||(temp->val<temp->next->val && temp->next->next->val<temp->next->val)){
                if(j==-1){
                    j=i;
                }
                else{
                    mn=min(mn,i-j);
                    mx+=i-j;
                    j=i;
                    ans[0]=mn;
                    ans[1]=mx;
                } 
            }
            i+=1;
            temp=temp->next;
        }
        return ans;
    }
};