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
public:
    
    TreeNode* trav(TreeNode* root,int key)
    {
        if(root == NULL)
        {
            return NULL;
        }
        
        if(root->val == key)
        {
            if(root->left == NULL && root->right == NULL)
            {
                return NULL;
            }
            if(root->left != NULL && root->right == NULL)
            {
                return root->left;
            }
            if(root->left == NULL && root->right != NULL)
            {
                return root->right;
            }
            TreeNode* temp = root->left;
            TreeNode* prev = root->right;
            TreeNode* curr = prev->left;
            
            while(curr != NULL)
            {
                prev = curr;
                curr = curr->left;
            }
            prev->left = temp;
            return root->right;
        }
        else
        {
            root->left = trav(root->left,key);
            root->right = trav(root->right,key);
        }
        
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        root = trav(root,key);
        return root;
        
    }
};