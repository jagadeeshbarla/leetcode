/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   // int ans = 0;
public:
    
    void travel(TreeNode* root,int max_e,int min_e,int &ans)
    {
        if(root == NULL)
        {
            return ;
        }
        max_e = max(max_e,root->val);
        min_e = min(min_e,root->val);
        ans = max(ans,max_e-min_e);
        travel(root->left,max_e,min_e,ans);
        travel(root->right,max_e,min_e,ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        
        int ans = 0;
        travel(root->left,root->val,root->val,ans);
        travel(root->right,root->val,root->val,ans);
        return ans;
    }
};