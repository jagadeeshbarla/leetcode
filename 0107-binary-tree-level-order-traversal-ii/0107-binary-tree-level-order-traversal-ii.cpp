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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        
        vector<TreeNode*>temp;
        temp.emplace_back(root);
        if(root==NULL)
        {
            return ans;
        }
        while(temp.size()!=0)
        {
            vector<int>temp_2;
            vector<TreeNode*>temp_1;
            for(int i=0;i<temp.size();i++)
            {
                if(temp[i]->left!=NULL)
                {
                    temp_1.emplace_back(temp[i]->left);
                }
                if(temp[i]->right!=NULL)
                {
                    temp_1.emplace_back(temp[i]->right);
                }
                temp_2.emplace_back(temp[i]->val);
            }
            ans.emplace_back(temp_2);
            temp = temp_1;
        }
        reverse(ans.begin(),ans.end());
        return ans ;
        
    }
};