#include<vector>

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
    void postorder_Traversal(vector<int>& post_order,TreeNode* root){
        if(!root){
            return;
        }
        postorder_Traversal(post_order,root->left);
        postorder_Traversal(post_order,root->right);
        post_order.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post_order;
        postorder_Traversal(post_order,root);
        return post_order;
    }
};