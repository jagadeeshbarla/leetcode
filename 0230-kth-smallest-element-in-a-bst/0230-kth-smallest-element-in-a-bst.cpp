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
    map<int,int>m;
    vector<int>v;
public:
   /* int trav_r(TreeNode* node,int prev)
    {
        if(node==NULL)
        {
            return 0;
        }
        int x =  1 + trav_l(node->left) + prev;
        m[x] = node->val;
        int y = trav_r(node->right,x) ;
        return x+y;
        
    }
    
    int trav_l(TreeNode* node,int prev)
    {
        if(node == NULL)
        {
            return 0;
        }
        int x =  1 + trav_l(node->left,prev) ;
        m[x] = node->val;
        int y = trav_r(node->right,x) ;
        return x+y;
    }*/
    
    void trav(TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        trav(root->left);
        v.emplace_back(root->val);
        trav(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        trav(root);
        return v[k-1];
    }
};