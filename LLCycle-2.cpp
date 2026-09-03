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
    ListNode *detectCycle(ListNode *head) 
    {
        unordered_set<ListNode*> seen;
        bool is_start=false;
        ListNode* node = head;
        ListNode* res = nullptr;
        while(!is_start && node != nullptr && node->next!=nullptr)
        {
            if(seen.contains(node))
            {
                is_start = true;
                res = node;
            }
            else
            {
                seen.insert(node);
                node = node->next;
            }
        }   
        return res; 
    }
};