/****
Author: Xianshi Xie
Email: xianshi.matt.xie@gmail.com

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
****/

ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || !head->next) return head;
        ListNode *dummy=new ListNode(0);
        dummy->next = head;
        ListNode *fast=dummy, *temp, *fn;
        int n=k;
        while (n-->0 && fast) fast=fast->next;
        //if (!fast) return dummy->next;
        
        ListNode *prev=dummy, *h=dummy->next;
        while (fast)
        {
            //reverse group of k nodes
            fn = fast->next;
            while (h->next!=fn)
            {
                temp=prev->next;
                prev->next=h->next;
                h->next=prev->next->next;
                prev->next->next=temp;
            }
            
            prev = h;
            fast = h;
            h = h->next;
            
            n=k;
            while (n-->0 && fast) fast=fast->next;
        }
        
        return dummy->next;
        
        
    }