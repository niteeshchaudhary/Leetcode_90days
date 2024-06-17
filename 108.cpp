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
    TreeNode* bst(vector<int>& nums,int l, int r){
        int mid=(l+r)/2;
        if(l>r){
            return nullptr;
        }
        if(l==r){
            return new TreeNode(nums[mid]);
        }
        TreeNode* md=new TreeNode(nums[mid]);
        TreeNode* lt=bst(nums,l,mid-1);
        TreeNode* rt=bst(nums,mid+1,r);
            md->left=lt;
            md->right=rt;

        return md;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size()-1;
        return bst(nums,0, n);;
        
    }
};