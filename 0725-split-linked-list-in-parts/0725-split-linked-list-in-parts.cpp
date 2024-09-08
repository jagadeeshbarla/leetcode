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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        ListNode* curr = head;
        while(curr != NULL)
        {
            size++;
            curr = curr->next;
        }
        
        int each_size = size/k;
        int extra_nodes = size%k;
        vector<ListNode*>ans(k);
        
        curr = head;
        int i = 0;
        while(i < k)
        {
            int temp = each_size;
            ListNode* temp_head = NULL;
            ListNode* temp_itr = NULL;
            while(temp--)
            {
                if(temp_head == NULL)
                {
                    temp_head = new ListNode(curr->val);
                    temp_itr = temp_head;
                }
                else
                {
                    temp_itr->next = new ListNode(curr->val);
                    temp_itr=temp_itr->next;
                }
                curr = curr->next;                
            }
            if(extra_nodes > 0)
            {
                if(temp_head == NULL)
                {
                    temp_head = new ListNode(curr->val);
                }
                else
                {
                    temp_itr->next = new ListNode(curr->val);
                }
                extra_nodes--;
                curr=curr->next;
            }
            ans[i++] = temp_head;
            
        }
        
        return ans;    
    }
};