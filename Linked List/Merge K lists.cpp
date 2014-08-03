//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.    

    class mycomp{        
        public:
        bool operator()(ListNode *n1, ListNode *n2)
        {
            return n1->val > n2->val; //great sign is for descending sorting
        }
    };
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {        
        int n=lists.size();
        if (n==0) return NULL;
        
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        ListNode *top;
        typedef std::priority_queue<Listode*,vector<ListNode*>,mycomp> mypq_type;
        mypq_type myqueue;
        
        for (int i=0; i<n; ++i)
        {
            if (lists[i]) 
                myqueue.push(lists[i]);
        }            
            
        while (!myqueue.empty())
        {
            top = myqueue.top();
            myqueue.pop();
            prev->next = top;
            prev = prev->next;
            if (top->next)
                myqueue.push(top->next);
        }        
        prev = dummy->next;
        delete dummy;        
        return prev;
    }
