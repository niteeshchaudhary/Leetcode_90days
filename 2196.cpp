#include<vector>
#include<unordered_map>
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_map<int,int> mpr;

        for(int i=0;i<descriptions.size();i++){
            mpr[descriptions[i][1]]++;
            if(!mp[descriptions[i][0]]){
                TreeNode* nd = new TreeNode(descriptions[i][0]);
                mp[descriptions[i][0]]=nd;
            }
            if(!mp[descriptions[i][1]]){
                TreeNode* lfnd = new TreeNode(descriptions[i][1]);
                mp[descriptions[i][1]]=lfnd;
            }  
            if(descriptions[i][2]){
                mp[descriptions[i][0]]->left=mp[descriptions[i][1]];
            }
            else{
                mp[descriptions[i][0]]->right=mp[descriptions[i][1]];
            }
        }
        for(int i=0;i<descriptions.size();i++){
            if(!mpr[descriptions[i][0]]){
                return mp[descriptions[i][0]];
            }
        }
        return new TreeNode(-1);
    }
};