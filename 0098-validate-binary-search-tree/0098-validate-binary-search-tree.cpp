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
    vector<int> dfs(TreeNode* root)
    {
        int flag = 0;
        vector<int>curr(3,0);
        if(root==NULL)
        {
            curr[0] = -1;        
            return curr;
        }
        vector<int> lp = dfs(root->left);
        vector<int> rp = dfs(root->right);
        
        if(lp[0]==-1 && rp[0]==-1)
        {
            curr[0] = 1;
            curr[1] = root->val;
            curr[2] = root->val;
            return curr;
        }
        else if( (rp[0]==1 && lp[0]==-1) || (lp[0]==1 && rp[0]==-1))
        {
             if(lp[0]==-1)
            {
                if(root->val < rp[1])
                {
                    curr[0] = 1;
                    curr[1] = min(rp[1],root->val);
                    curr[2] = max(rp[2],root->val);
                }
                else
                {
                    curr[0] = 0;
                }
            }
            else
            {
                if(root->val > lp[2])
                {
                    curr[0] = 1;
                    curr[1] = min(lp[1],root->val);
                    curr[2] = max(lp[2],root->val);
                    
                }
                else
                {
                    curr[0] = 0;
                }
                
            }
           
        }
        else if(lp[0]==1 && rp[0]==1)
        {
            if(lp[2] < root->val)
            {
                curr[0] = 1;
                curr[1] = min(lp[1],root->val);
                curr[2] = max(lp[2],root->val);
            }
            else
            {
                curr[0] = 0;
            }
            if(rp[1] > root->val)
            {
                curr[0] *= 1;
                curr[1] = min({curr[1],rp[1],root->val});
                curr[2] = max({curr[2],rp[2],root->val});
            }
            else
            {
                curr[0] = 0;
            }
            
        }
        else
        {
            curr[0]=0;
        }
        return curr;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> lp = dfs(root);
        return lp[0];
        
    }
};