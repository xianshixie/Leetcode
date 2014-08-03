/****
Author: Xianshi Xie
Email: xianshi.matt.xie@gmail.com

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

****/

RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode *newhead = new RandomListNode(head->label);
        RandomListNode *c1=head, *c2=newhead;
        unordered_map<RandomListNode*, RandomListNode*> nodemap;
        nodemap[head] = newhead;
        
        while (c1->next)
        {
            c2->next = new RandomListNode(c1->next->label);
            c1 = c1->next;
            c2 = c2->next;
            nodemap[c1] = c2;
        }
        
        c1 = head;
        while (c1)
        {
            nodemap[c1]->random = nodemap[c1->random];
            c1 = c1->next;
        }
        
        return newhead;
        
    }
