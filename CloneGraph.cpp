//Problem: Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        typedef UndirectedGraphNode Node;
        queue<Node*> que;
        unordered_map<Node*,Node*> map;
        if (!node) return NULL;
        Node *entry=new Node(node->label);
        map[node]=entry;
        que.push(node);
        
        while (!que.empty()){
            Node *myfront=que.front();
            que.pop();
            
            for (int i=0; i<myfront->neighbors.size();++i){
                Node *neighb=myfront->neighbors[i];
                if (!map[neighb]){
                    Node *new_neighb=new Node(neighb->label);
                    map[neighb]=new_neighb;
                    que.push(neighb);
                }
                
                map[myfront]->neighbors.push_back(map[neighb]);
                
            }
        }
        
        return entry;
    }
};