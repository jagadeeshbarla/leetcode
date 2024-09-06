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
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        map<int,int>m;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            m.insert({nums[i],1});
        }
        while(head !=NULL && m.find(head->val) != m.end())
        {
            head = head->next;
        }
        ListNode* prev = head;
        ListNode* curr = prev->next;
        while( curr != NULL)
        {
            if(m.find(curr->val) != m.end())
            {
                prev->next = curr->next;
                
            }
            else
            {
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};