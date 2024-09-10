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
    int gcd(int a,int b)
    {
        if( a > b){
            return gcd(b,a);
        }
        if(b%a == 0)
        {
            return a;
        }
        else
        {
            return gcd(b%a,a);
        }
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next != NULL)
        {
            ListNode* curr = head;
            ListNode* prev = curr;    
            curr=curr->next;
            while(curr != NULL)
            {
                ListNode* temp = new ListNode(gcd(prev->val,curr->val));
                prev->next = temp;
                temp->next = curr;
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};