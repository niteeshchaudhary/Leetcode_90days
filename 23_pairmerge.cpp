#include<vector>
#include<iostream>
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
    ListNode* merger(ListNode* list0,ListNode* list1){ 
        ListNode* answer=new ListNode(0);
        ListNode* ans=answer;
        ListNode* l1=list0;
        ListNode* l2=list1;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val < l2->val){
                ans->next=l1;
                ans=ans->next;
                l1=l1->next;
            }else{
                ans->next=l2;
                ans=ans->next;
                l2=l2->next;
            }
        }
        if(l1!=nullptr){
            ans->next=l1;
        }
        if(l2!=nullptr){
            ans->next=l2;
        }
        return answer->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* answer=new ListNode(0);
        if(lists.size()==0){
            return answer->next;
        }
        if(lists.size()==1){
            return lists[0];
        }
        int length=lists.size();
        while(length!=1){
            if(length%2){
                int j=0,i=0;
                for(;i<length-1;i+=2,j++){
                    lists[j]=merger(lists[i],lists[i+1]);
                }
                lists[j-1]=merger(lists[j-1],lists[i]);
                length=j;
            }
            else{
                int j=0;
                for(int i=0;i<length;i+=2,j++){
                    lists[j]=merger(lists[i],lists[i+1]);
                }
                length=j;
            }
        }
        return lists[0];
    }
};