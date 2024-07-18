#include<vector>
#include<iostream>
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
    int count=0;
    vector<int> dfs(TreeNode* root,int distance) {
        if(!root){
            return {};
        }
        if(!root->left && !root->right){
            return {1};
        }
        
        vector<int> data;
        vector<int> ldata=dfs(root->left,distance);
        vector<int> rdata=dfs(root->right,distance);
        for(int i=0;i<ldata.size();i++){
            if(ldata[i]+1<=distance){
                data.push_back(ldata[i]+1);
            }
            for(int j=0;j<rdata.size();j++){
                if(ldata[i]+rdata[j]<=distance){
                    count++;
                }
            }
        }
        for(int j=0;j<rdata.size();j++){
            if(rdata[j]+1<=distance){
                data.push_back(rdata[j]+1);
            }
        }
        return data;
    }
    int countPairs(TreeNode* root, int distance) {
        if(!root){
            return 0;
        }
        vector<int> ds=dfs(root,distance);
        return count;
    }
};