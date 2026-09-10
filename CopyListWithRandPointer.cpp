/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* node = head;
        if(head == nullptr)
        {
            return head;
        }
        unordered_map<Node*, Node*> mp;
        //first pass to deep copy rand nodes
        while(node!=nullptr)
        {
            mp[node] = new Node(node->val);
            node = node->next;
        }
        node = head;
        //now connect nodes
        while(node!=nullptr)
        {
            mp[node] -> next = mp[node->next];
            mp[node] -> random = mp[node->random];
            node = node->next;
        }
        return mp[head];
    }
};