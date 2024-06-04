
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
        ListNode* extra=new ListNode(0);
        extra->next=head;
        ListNode* temp=head;
        ListNode* temp2=extra;
        for(int i=0;i<n;i++){
                temp=temp->next;
        }
        while(temp){
            temp=temp->next;
            temp2=temp2->next;
        }
        temp2->next=temp2->next->next;
        return extra->next;
    }
};