#include<vector>
#include<queue>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* answer=new ListNode(0);
        ListNode* temp=answer;
        if(lists.size()==0){
            return answer->next;
        }
        if(lists.size()==1){
            return lists[0];
        }
        priority_queue<pair<int,ListNode*>> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i])
                pq.push({-1*lists[i]->val,lists[i]});
        }
        while(!pq.empty()){
            pair<int,ListNode*> tp=pq.top();
            pq.pop();
            temp->next=tp.second;
            temp=temp->next;
            if(tp.second->next)
                pq.push({-1*tp.second->next->val,tp.second->next});
        }
        return answer->next;
    }
};