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
public:
    
    TreeNode* fun(vector<int>&v , int i,int j)
    {
        if(i > j)
        {
            return NULL;
        }
        
        int mid = (i+j)/2;
        
        TreeNode* curr = new TreeNode(v[mid]);
        if(i == j)
        {
            return curr;
        }
        //left part
            curr->left = fun(v,i,mid-1);
        //right part
            curr->right = fun(v,mid+1,j);
        
        return curr;
    
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(head == NULL)
        {
            return NULL;
        }
        
        vector<int>v;
        ListNode* curr = head;
        
        while(curr != NULL)
        {
            v.emplace_back(curr->val);
            curr = curr->next;
        }
        
        
        return fun(v,0,v.size()-1);
    }
};