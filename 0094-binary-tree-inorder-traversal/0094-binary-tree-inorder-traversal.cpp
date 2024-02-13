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
    
    void left_tree(TreeNode* curr , stack<TreeNode*> &st)
    {
        if(curr == NULL)
        {
            return ;
        }
        st.push(curr);
        left_tree(curr->left,st);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        stack<TreeNode*>st;
        left_tree(curr,st);
        vector<int> ans;
        
        while(!st.empty())
        {
            TreeNode* temp = st.top();
            st.pop();
            ans.emplace_back(temp->val);
            if(temp -> right != NULL)
            {
                left_tree(temp->right,st);
            }
        }
        return ans;
    }
};