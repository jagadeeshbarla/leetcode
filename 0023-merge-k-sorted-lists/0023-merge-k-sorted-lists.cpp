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
    ListNode* mergeKLists(vector<ListNode*>& l) {
        
        ListNode* ans = NULL;
        ListNode* curr = NULL;
        bool flag = true;
            
        while(flag)
        {
            flag = false;
            int min_e = INT_MAX;
            ListNode* min_a = NULL;
            int mi=0;
            for(int i=0;i<l.size();i++)
            {
                if(l[i] == NULL)
                {
                    continue;
                }
                if(l[i]->val < min_e )
                {
                    min_e = l[i]->val;
                    min_a = l[i];
                    mi = i;
                }
            }
            
            if(min_a !=NULL)
            {
                l[mi] = l[mi]->next;
                if(ans==NULL)
                {
                    ans = new ListNode(min_e);
                    min_a = min_a->next;
                    curr = ans;
                }
                else
                {
                    ListNode* temp = new ListNode(min_e);
                    min_a = min_a->next;
                    curr->next = temp;
                    curr = temp; 
                }
                flag = true;
            }
        }
        return ans;
    }
};