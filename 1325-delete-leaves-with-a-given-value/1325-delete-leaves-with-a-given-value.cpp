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
    
    bool fun(TreeNode* node,int target)
    {
        if(node == NULL)
        {
            return true;
        }
        
        if(fun(node->left,target))
        {
            node->left = NULL;
        }
        if(fun(node->right,target))
        {
            node->right = NULL;
        }
        if(node->val == target && node->right == NULL && node->left == NULL)
        {
            return true;
        }
        return false;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        if(fun(root,target))
        {
            return NULL;
        }
        return root;
    }
};