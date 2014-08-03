/******************
Sort a linked list in O(n log n) time using constant space complexity.
******************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeList(ListNode *h1, ListNode *h2)
    {
        if (!h1) return h2;
        if (!h2) return h1;
        
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        
        while (h1 && h2)
        {
            if (h1->val <= h2->val)
            {
                prev->next = h1;
                prev = prev->next;
                h1=h1->next;
            }
            else
            {
                prev->next = h2;
                prev = prev->next;
                h2 = h2->next;
            }
        }
        
        prev->next = h1?h1:h2;
        
        return dummy->next;
    }
    
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *slow=head, *fast=head, *last=head;
        while (fast && fast->next)
        {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        last->next = NULL;
        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);
        
        return mergeList(left,right);
        
    }
};