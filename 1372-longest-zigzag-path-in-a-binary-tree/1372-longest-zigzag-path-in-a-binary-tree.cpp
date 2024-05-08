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
    int max_len = 0;
    
    
public:
    
    void trav(TreeNode* root , char ch, int curr_len)
    {
        max_len = max(curr_len,max_len);
        if(root == NULL)  
        {
            return ;
        }
        if(root -> left != NULL && ch == 'r')
        {
            trav(root->left,'l',curr_len+1);       
        }
        if(root -> right != NULL && ch == 'l')
        {
            trav(root->right,'r',curr_len+1);
        }
        if(root -> left != NULL  && ch =='f' )
        {
            trav(root->left,'l',1);
        }
        if(root -> right != NULL &&   ch =='f' )
        {
            trav(root->right,'r',1);
        }
        if(root -> left != NULL && ch == 'l'  )
        {
            trav(root->left,'l',1);
            //trav(root,'f',0);
        }
        if(root -> right != NULL &&  ch == 'r'  ) 
        {
            trav(root->right,'r',1);
            //trav(root,'f',0);
        }
    
    }
    
    
    
    
    int longestZigZag(TreeNode* root) {
        
        if(root->left == NULL && root->right == NULL )
        {
            return 0;
        }
        trav(root,'f',0);
        return max_len;        
        
    }
};

