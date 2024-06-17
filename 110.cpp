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
    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }
        int lh=dfs(root->left);
        if(lh<0){
            return -1;
        }
        int rh=dfs(root->right);
        if(rh<0||abs(lh-rh)>1){
            return -1;
        }
        return max(lh,rh)+1;

    }
    bool isBalanced(TreeNode* root) {
        if(dfs(root)<0){
            return false;
        }
        return true;
    }
};