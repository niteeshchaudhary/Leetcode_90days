
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
    bool dfs(TreeNode* root,int currsum,int targetSum){
        if(!root){
            return false;
        }
        int val=currsum+root->val;
        if(!root->left && !root->right && val==targetSum){
            return true;
        }
        bool lft=dfs(root->left,val,targetSum);
        if(lft)
            return lft;
        return dfs(root->right,val,targetSum);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,0,targetSum);
    }
};