/**
 *Problem definition: Sort a linked list using insertion sort.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *dummy=new ListNode(INT_MIN);
        dummy->next=head;
        ListNode *tail=head, *curr, *temp;
        while (tail->next){
            temp=tail->next;
            if (temp->val>=tail->val) tail=tail->next;
            else{
                curr=dummy;
                tail->next=temp->next;
                while (temp->val>curr->next->val){
                    curr=curr->next;
                }
                temp->next=curr->next;
                curr->next=temp;
            }
        }
        
        return dummy->next;
    }
};