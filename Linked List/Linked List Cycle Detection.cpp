/************************
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
*************************/

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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode *slow=head, *fast=head;
        
        while (fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast) break;
        }
        
        if (!fast->next || !fast->next->next) return NULL;
        while (head!=fast){
            head=head->next;
            fast=fast->next;
        }
        return fast;
    }
};