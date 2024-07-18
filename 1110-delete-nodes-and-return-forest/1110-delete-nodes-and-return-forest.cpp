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
    void trav(TreeNode* root,map<int,int>&m,vector<TreeNode*>&ans)
    {
           //ans.emplace_back(root);
        if(root->left != NULL)
        {
            if(m.find(root->left->val) != m.end()) // we have to delete
            {
                queue<vector<TreeNode*>>q;
                vector<TreeNode*>temp;
                temp.emplace_back(root->left);
                q.push(temp);
                root->left = NULL;
                while(!q.empty())
                {
                    vector<TreeNode*> curr = q.front();
                    q.pop();
                    vector<TreeNode*>next;
                    for(int i = 0 ; i < curr.size() ; i++)
                    {
                        if(m.find(curr[i]->val) != m.end() )
                        {
                            if(curr[i]->left != NULL)
                            {
                                next.emplace_back(curr[i]->left);
                            }
                            if(curr[i]->right != NULL)
                            {
                                next.emplace_back(curr[i]->right);
                            }
                            
                        }
                        else
                        {
                            ans.emplace_back(curr[i]);
                            trav(curr[i],m,ans);
                        }
                    }
                    if(next.size() > 0 )
                    {
                        q.push(next);
                    }
                }
                
            }
            else
            {
              trav(root->left,m,ans);  
            }
        }
        if(root->right != NULL)
        {
            if(m.find(root->right->val) != m.end()) // we have to delete
            {
                queue<vector<TreeNode*>>q;
                vector<TreeNode*>temp;
                temp.emplace_back(root->right);
                q.push(temp);
                root->right = NULL;
                while(!q.empty())
                {
                    vector<TreeNode*> curr = q.front();
                    q.pop();
                    vector<TreeNode*>next;
                    for(int i = 0 ; i < curr.size() ; i++)
                    {
                        if(m.find(curr[i]->val) != m.end() )
                        {
                            if(curr[i]->left != NULL)
                            {
                                next.emplace_back(curr[i]->left);
                            }
                            if(curr[i]->right != NULL)
                            {
                                next.emplace_back(curr[i]->right);
                            }
                            
                        }
                        else
                        {
                            ans.emplace_back(curr[i]);
                            trav(curr[i],m,ans);
                        }
                    }
                    if(next.size() > 0 )
                    {
                        q.push(next);
                    }
                }
                
            }
            else
            {
              trav(root->right,m,ans);  
            }
        }
        
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        map<int,int>m;
        for(int i = 0 ; i < to_delete.size() ; i++)
        {
            m.insert({to_delete[i],1});
        }
        vector<TreeNode*>ans;
        
        queue<vector<TreeNode*>>q;
        vector<TreeNode*>temp;
        temp.emplace_back(root);
        q.push(temp);
        
        while(!q.empty())
        {
            vector<TreeNode*> curr = q.front();
            q.pop();
            vector<TreeNode*>next;
            for(int i = 0 ; i < curr.size() ; i++)
            {
                if(m.find(curr[i]->val) != m.end() )
                {
                    if(curr[i]->left != NULL)
                    {
                        next.emplace_back(curr[i]->left);
                    }
                    if(curr[i]->right != NULL)
                    {
                        next.emplace_back(curr[i]->right);
                    }
                }
                else
                {
                    ans.emplace_back(curr[i]);
                    trav(curr[i],m,ans);
                }
            }
            if(next.size() > 0 )
            {
                q.push(next);
            }
        }
        
        return ans;
        
    }
};