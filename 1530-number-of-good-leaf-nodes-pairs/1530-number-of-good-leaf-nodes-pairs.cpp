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
    void trav(TreeNode* root , map<int,string>& map, string curr)
    {
        if(root->left == NULL && root->right == NULL)
        {
            while(map.find(root->val) != map.end())
            {
                root->val++;
            }
            map.insert({root->val,curr});
            return;
        }
        if(root->left != NULL )
        {
            trav(root->left,map,curr+'L');
        }
        if( root->right != NULL)
        {
            trav(root->right,map,curr+'R');
        }
    }
    int dist_check(string s1 , string s2)
    {
        int same_directions = 0;
        
        int i = 0 ; 
        int j = 0 ;
        while(i < s1.size() && j < s2.size())
        {
            if(s1[i] == s2[j])
            {
                same_directions++;
            }
            else
            {
                break;
            }
            i++;
            j++;
        }
        return s1.size()+s2.size()-(2*same_directions);
    }
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        map<int,string>m;
        trav(root,m,"");
        
        map<int,string>::iterator itr;
        for(itr = m.begin() ; itr != m.end() ; itr++)
        {
            //cout<<itr->first<<" "<<itr->second<<endl;
            map<int,string>::iterator itr1 = itr;
            itr1++;
            while(itr1 != m.end())
            {
                if(dist_check(itr->second,itr1->second) <= distance)
                {
                    ans++;
                }
                itr1++;
            }
        }
        
        //cout<<endl;
        return ans;
        
    }
};