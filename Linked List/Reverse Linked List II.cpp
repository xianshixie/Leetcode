/****
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.
****/

ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || !head->next) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev=dummy, *st, *tmp;
        int dist = n-m;
        
        while (m-->1)
            prev = prev->next;
            
        st = prev->next;
        
        while (dist>0)
        {
            tmp = st->next;
            st->next = tmp->next;
            tmp->next = prev->next;
            prev->next = tmp;
            dist--;
        }
        
        return dummy->next;
}