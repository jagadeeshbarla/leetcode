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
        
    ListNode* reverse(ListNode* head)
    {
        // if(head == NULL || head->next == NULL)
        // {
        //     return head;
        // }
        
        ListNode* curr = head;
        while(curr->next != NULL)
        {
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            temp->next = head;
            head = temp;
        }
        return head;
    }
    ListNode* doubleIt(ListNode* head) {
        
        
        ListNode* curr = head;
        while(curr->next != NULL)
        {
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            temp->next = head;
            head = temp;
        }
        int carry = 0;
        curr = head;
        while(curr != NULL)
        {
            int curr_val = curr->val;
            curr_val *= 2;
            curr_val += carry;
            carry = 0;
            
            carry = curr_val / 10;
            curr->val = curr_val%10;
            if(curr->next == NULL && carry > 0)
            {
                ListNode* newnode = new ListNode(carry);
                curr->next = newnode;
                break;
            }
            
            curr = curr->next;
        }
        curr = head;
        while(curr->next != NULL)
        {
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            temp->next = head;
            head = temp;
        }
        
        //reverse(head);
        return head;
        
    }
};