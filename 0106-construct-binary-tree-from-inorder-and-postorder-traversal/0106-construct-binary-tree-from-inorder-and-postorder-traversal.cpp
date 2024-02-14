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
    TreeNode* buildTree(vector<int>& iov, vector<int>& psv) {
        if(psv.size() == 0)
        {
            return NULL;
        }
        
        vector<int>temp_pos_l,temp_pos_r,temp_ino_l,temp_ino_r;
        map<int,int>ino_map_r,ino_map_l;
        int curr_root = psv[psv.size()-1];
        
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
        
        for(int i = 0 ; i < psv.size() ; i++)
        {
            if(ino_map_l.count(psv[i]) == 1)
            {
                temp_pos_l.emplace_back(psv[i]);
            }
            else if(ino_map_r.count(psv[i]) == 1)
            {
                temp_pos_r.emplace_back(psv[i]);
            }
        }
        
        TreeNode *curr_node = new TreeNode(curr_root);
        curr_node ->left = buildTree(temp_ino_l,temp_pos_l);
        curr_node -> right = buildTree(temp_ino_r,temp_pos_r);
        return curr_node;
        
    }
};