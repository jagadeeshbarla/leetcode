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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,bool>mr;
        unordered_map<int,TreeNode*>m;
        int root_val;
        for(int i = 0 ; i < descriptions.size() ; i++)
        {
            mr.insert({descriptions[i][0],true});
            
            if (m.find(descriptions[i][0]) != m.end())
            {
                if(m.find(descriptions[i][1]) != m.end() ) //it's child is created earlier
                {
                    if(descriptions[i][2] == 1) 
                    {
                        m[descriptions[i][0]]->left = m[descriptions[i][1]]; 
                    }
                    else
                    {
                        m[descriptions[i][0]]->right = m[descriptions[i][1]]; 
                    }
                }
                else // it's child  not created till now
                {
                    TreeNode* child_node = new TreeNode(descriptions[i][1]);
                    m.insert({descriptions[i][1],child_node});
                    if(descriptions[i][2] == 1)
                    {
                        m[descriptions[i][0]]->left = m[descriptions[i][1]]; 
                    }
                    else
                    {
                        m[descriptions[i][0]]->right = m[descriptions[i][1]]; 
                    }
                }
                
            }
            else
            {
                TreeNode* curr_node = new TreeNode(descriptions[i][0]); // created for 20
                m.insert({descriptions[i][0],curr_node});
                if(m.find(descriptions[i][1]) != m.end() ) //it's child is created earlier
                {
                    if(descriptions[i][2] == 1) 
                    {
                        curr_node->left = m[descriptions[i][1]]; 
                    }
                    else
                    {
                        curr_node->right = m[descriptions[i][1]]; 
                    }
                }
                else // it's child  not created till now
                {
                    TreeNode* child_node = new TreeNode(descriptions[i][1]);
                    m.insert({descriptions[i][1],child_node});
                    if(descriptions[i][2] == 1)
                    {
                        curr_node->left = m[descriptions[i][1]]; 
                    }
                    else
                    {
                        curr_node->right = m[descriptions[i][1]]; 
                    }
                }
            }
        }
        for(int i = 0 ; i < descriptions.size();i++)
        {
            mr[descriptions[i][1]] = false;
        }
        for(int i = 0 ; i < descriptions.size();i++)
        {
            if(mr[descriptions[i][0]] == true)
            {
                root_val = descriptions[i][0];
            }
        }       
              
        return m[root_val]; 
        
    }
};