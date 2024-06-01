#include<vector>
#include<stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vc;
        if(root==nullptr){
            return vc;
        }
        TreeNode* temp=root;
        stack<TreeNode*> st;
        st.push(temp);
        while(!st.empty()){
            while(temp!=nullptr){
                temp=temp->left;
                if(temp)
                    st.push(temp);
            }
            temp=st.top();
            vc.push_back(temp->val);
            st.pop();
            temp=temp->right;
            if(temp)
                st.push(temp);
        }
        return vc;
    }
};
// Recursive Solution
// class Solution {
//     vector<int> vc;
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         if(root==nullptr){
//             return vc;
//         }
//         inorderTraversal(root->left);
//         vc.push_back(root->val);
//         inorderTraversal(root->right);
//         return vc;
//     }
// };