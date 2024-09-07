/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool flag = false;
public:
    void trav(TreeNode* root , ListNode* head , ListNode* curr,map<pair<int,int>,int>&coord ,int x,int y)
    {
        if(root == NULL || flag == true)
        {
            return;
        }
        if(root->val == head->val && head != curr && coord.find(make_pair(x,y)) == coord.end() )
        {
            coord.insert({make_pair(x,y),1});
            trav(root,head,head,coord,x,y);
        }
        if(root->val == curr->val)
        {
            if(curr->next == NULL)
            {
                flag = true;
                return;
            }
            curr=curr->next;
        }
        else
        {
            curr=head;
        }

        trav(root->left,head,curr,coord,x+1,y-1);
        trav(root->right,head,curr,coord,x+1,y+1);
        
        
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        map<pair<int,int>,int>coord;
        trav(root,head,head,coord,0,0);
        return flag;
    }
};