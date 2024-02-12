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
    TreeNode* buildTree(vector<int>& pov, vector<int>& iov) {
        if(pov.size() == 0)
        {
            return NULL;
        }
        
        vector<int>temp_pre_l,temp_pre_r,temp_ino_l,temp_ino_r;
        map<int,int>ino_map_r,ino_map_l;
        int curr_root = pov[0];
        
        int flag = 0;
        for(int i = 0 ; i < iov.size() ; i++)
        {
            if(iov[i] == curr_root)
            {
                flag = 1;
            }
            else if(flag == 0)
            {
                temp_ino_l.emplace_back(iov[i]);   
                ino_map_l.insert({iov[i],1});
            }
            else
            {
                temp_ino_r.emplace_back(iov[i]);
                ino_map_r.insert({iov[i],1});
            }
        }
        
        for(int i = 0 ; i < pov.size() ; i++)
        {
            if(ino_map_l.count(pov[i]) == 1)
            {
                temp_pre_l.emplace_back(pov[i]);
            }
            else if(ino_map_r.count(pov[i]) == 1)
            {
                temp_pre_r.emplace_back(pov[i]);
            }
        }
        
        TreeNode *curr_node = new TreeNode(curr_root);
        curr_node ->left = buildTree(temp_pre_l,temp_ino_l);
        curr_node -> right = buildTree(temp_pre_r,temp_ino_r);
        return curr_node;
    }
};