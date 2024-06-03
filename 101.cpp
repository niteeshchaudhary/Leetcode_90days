
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
    bool traverse(TreeNode* rootl,TreeNode* rootr){
        if(rootl && rootr){
            if(rootl->val!=rootr->val){
                return false;
            }
            bool lc=traverse(rootl->left,rootr->right);
            if(!lc)
                return false;
            return traverse( rootl->right, rootr->left);
        }
        if(!rootl && !rootr){
            return true;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return traverse(root->left,root->right);
        
    }
};