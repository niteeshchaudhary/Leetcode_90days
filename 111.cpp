#include<queue>
#include<vector>
#include<cmath>
#include <utility>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        if(!root){
            return 0;
        }
        q.push({root,1});
        while(!q.empty()){
            pair<TreeNode*,int> tr=q.front();
            q.pop();
            if(!tr.first->left && !tr.first->right){
                return tr.second;
            }
            if(tr.first->left){
                q.push({tr.first->left,tr.second+1});
            }
            
            if(tr.first->right){
                q.push({tr.first->right,tr.second+1});
            }
        }
        return 0;
    }
};