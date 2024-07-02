struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ls= new ListNode();
        ListNode* t3=ls;
        if(l1==nullptr){
            return l2;
        }
        else if(l2==nullptr){
            return l1;
        }
        char carry=0;
        while(l1!=nullptr && l2!=nullptr){
            carry=l1->val+l2->val+carry;
            t3->next=new ListNode(carry%10);
            carry=carry/10;
            t3=t3->next;
            l1=l1->next;
            l2=l2->next;
            if(l1==nullptr){
                l1=l2;
                break;
            }
        }
        while(l1!=nullptr){
            carry=l1->val+carry;
            t3->next=new ListNode(carry%10);
            carry=carry/10;
            t3=t3->next;
            l1=l1->next;
        }
        if(carry>0){
            t3->next=new ListNode(carry);
            t3->next;
        }
        ListNode* rs=ls->next;
        delete ls;
        return  rs;
    }
};