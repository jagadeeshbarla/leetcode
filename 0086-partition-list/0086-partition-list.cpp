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
    ListNode* partition(ListNode* head, int x) 
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode* curr = head;
        ListNode* lh = NULL;
        ListNode* gh = NULL;
        ListNode* lc = NULL;
        ListNode* gc = NULL;
        
        
        while(curr != NULL)
        {
            if(curr->val < x)
            {
                if(lh == NULL)
                {
                    lh = new ListNode(curr->val);
                    lc = lh;
                }
                else
                {
                    ListNode* temp = new ListNode(curr->val);
                    lc->next = temp;
                    lc = temp;
                    lc->next = NULL;
                }
                
            }
            else
            {
                if(gh == NULL)
                {
                    gh = new ListNode(curr->val);
                    gc = gh;
                }
                else
                {
                    ListNode* temp = new ListNode(curr->val);
                    gc->next = temp;
                    gc = temp;
                    gc->next = NULL;
                }
                
            }
            curr = curr->next;
        }
        if(lc == NULL)
        {
            return gh;
        }
        
        lc->next = gh;
        
        
            
        
        return lh;
    }
};