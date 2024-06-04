
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total=0;
        ListNode* temp=head;
        while(temp){
            total++;
            temp=temp->next;
        }
        temp=head;
        if(n==total){
            temp=head->next;
            return temp;
        }
        else{
            n=total-n;
            for(int i=1;i<n;i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
        }
        return head;
        
    }
};