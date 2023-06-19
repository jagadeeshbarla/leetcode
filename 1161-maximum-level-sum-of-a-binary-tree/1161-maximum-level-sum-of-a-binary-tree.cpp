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
    int maxLevelSum(TreeNode* root) 
    {
        int max_s = root->val;
        int max_o=1;
        vector<TreeNode*>v;
        v.emplace_back(root);
        vector<vector<TreeNode*>>q;
        q.emplace_back(v);
        int curr_o=1;
        while(q.size()!=0)
        {
            int curr_s = 0;
            vector<TreeNode*> temp = q[0];
            vector<TreeNode*> next;
            q.pop_back();
            for(int i=0;i<temp.size();i++)
            {
                if(temp[i]->left!=NULL)
                {
                    next.emplace_back(temp[i]->left);
                }
                if(temp[i]->right!=NULL)
                {
                    next.emplace_back(temp[i]->right);
                }
                curr_s+=temp[i]->val;
            }
            if(next.size()>0)
            {
                q.emplace_back(next);
            }
            if(curr_s > max_s)
            {
                max_s = curr_s;
                max_o = curr_o;
            }
            curr_o++;
        }
        return max_o;
        
    }
};