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
    vector<int>t;
    int i=0;
    
public:
    void trav(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        t.emplace_back(root->val);
        trav(root->left);
        trav(root->right);
    }
    
    
    void ctrav(TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        ctrav(root->left);
        root->val = t[i];
        i+=1;
        ctrav(root->right);
    }
    void recoverTree(TreeNode* root) {
        trav(root);
        sort(t.begin(),t.end());
        ctrav(root);
    }
};