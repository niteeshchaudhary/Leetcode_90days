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
    void bst(TreeNode* tree,vector<int>& nums,int l, int r){
        int mid=(l+r)/2;
        if(l>r){
            return;
        }
        TreeNode* tn=new TreeNode(nums[mid]);
        if(nums[mid]<tree->val){
            tree->left=tn;
        }
        else if(nums[mid]>tree->val){
            tree->right=tn;
        }
        bst(tn,nums,l, mid-1);
        bst(tn,nums,mid+1, r);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size()-1;
        int mid=(n)/2;
        TreeNode* tn=new TreeNode(nums[mid]);
        bst(tn,nums,0, mid-1);
        bst(tn,nums,mid+1, n);
        return tn;
    }
};