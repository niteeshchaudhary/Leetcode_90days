#include <iostream>
#include <vector>
#include <algorithm>
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* frst=head;
        ListNode* second=head;
        int sum=0;
        while(second->next){
            second=second->next;
            sum=0;
            while(second->val!=0){
                sum+=second->val;
                second=second->next;
            }
            frst->next=new ListNode(sum);
            frst=frst->next;
            frst->next=second;
        }
        frst->next=nullptr;

        return head->next;
    }
};