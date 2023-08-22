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
    vector<int> largestValues(TreeNode* root) {
        
        vector<int>ans;
        if(root == NULL)
        {
            return ans;
        }
        queue<vector<TreeNode*>>q;
        vector<TreeNode*>temp;
        temp.emplace_back(root);
        q.push(temp);
        while(!q.empty())
        {
            int maxi = INT_MIN;
            vector<TreeNode*> t = q.front();
            vector<TreeNode*> next;
            q.pop();
            for(int i = 0;i < t.size() ;i++)
            {
                if(t[i]->left != NULL)
                {
                    next.emplace_back(t[i]->left);
                }
                if(t[i]->right != NULL)
                {
                    next.emplace_back(t[i]->right);
                }
                
                maxi = max( maxi , t[i]->val );
                
            }
            ans.emplace_back(maxi);
            
            if(next.size() !=0 )
            {
                q.push(next);
            }
        }
        return ans;
    }
};