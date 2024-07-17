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
    void trav(TreeNode* root,vector<TreeNode*>& forest,bool *td){
        if (!root){
            return;
        }
        trav(root->left,forest,td);
        trav(root->right,forest,td);
        if(root->left && td[root->left->val]){
            if(root->left->left && !td[root->left->left->val]){
                forest.push_back(root->left->left);
            }
            if(root->left->right && !td[root->left->right->val]){
                forest.push_back(root->left->right);
            }
            root->left=nullptr;
        }
        if(root->right && td[root->right->val]){
            if(root->right->left && !td[root->right->left->val]){
                forest.push_back(root->right->left);
            }
            if(root->right->right && !td[root->right->right->val]){
                forest.push_back(root->right->right);
            }
            root->right=nullptr;
        }

    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        bool td[1001];
        TreeNode* empty=new TreeNode(-1);
        empty->left=root;
        for(int i=0;i<to_delete.size();i++){
            td[to_delete[i]]=true;
        } 
        if(!td[root->val]){
            forest.push_back(root);
        }
        trav(empty,forest,td);
        
        return forest;
    }
};