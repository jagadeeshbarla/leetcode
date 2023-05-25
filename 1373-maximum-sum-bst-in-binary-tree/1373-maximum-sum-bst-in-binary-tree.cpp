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
/*
-1 null
0 false
1 true

arr[0]=flag 
arr[1]=prev sum
arr[2]=prev min
arr[3]=prev max
*/
class Solution {
    int maxi = 0;
public:
    vector<int> dfs(TreeNode* root)
    {
        int sum = 0;
        int flag = 0;
        vector<int>curr(4,0);
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
            curr[2] = curr[1];
            curr[3] = curr[1];
            maxi = max(maxi,curr[2]);
            return curr;
        }
        else if( (rp[0]==1 && lp[0]==-1) || (lp[0]==1 && rp[0]==-1))
        {
             if(lp[0]==-1)
            {
                if(root->val < rp[2])
                {
                    curr[0] = 1;
                    curr[1] = root->val+rp[1];
                    curr[2] = min(rp[2],root->val);
                    curr[3] = max(rp[3],root->val);
                    maxi = max(maxi,curr[1]);
                }
                else
                {
                    curr[0] = 0;
                }
            }
            else
            {
                if(root->val > lp[3])
                {
                    curr[0] = 1;
                    curr[1] = root->val+lp[1];
                    curr[2] = min(lp[2],root->val);
                    curr[3] = max(lp[3],root->val);
                    maxi = max(maxi,curr[1]);
                }
                else
                {
                    curr[0] = 0;
                }
                
            }
           
        }
        else if(lp[0]==1 && rp[0]==1)
        {
            if(lp[3] < root->val)
            {
                curr[0] = 1;
                curr[1] = root->val + lp[1];
                curr[2] = min(lp[2],root->val);
                curr[3] = max(lp[3],root->val);
            }
            else
            {
                curr[0] = 0;
            }
            if(rp[2] > root->val)
            {
                curr[0] = 1;
                curr[1] += rp[1];
                curr[2] = min({curr[2],rp[2],root->val});
                curr[3] = max({curr[3],rp[3],root->val});
            }
            else
            {
                curr[0] = 0;
            }
            if(curr[0]!=0)
            {
                maxi = max(maxi,curr[1]);
            }
            
        }
        else
        {
            curr[0]=0;
        }
        return curr;
    }
    int maxSumBST(TreeNode* root) 
    {
        dfs(root);
        return maxi;
    }
};