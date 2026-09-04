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
    bool hasCycle(ListNode *head) {
        ListNode* node = head;
        ListNode* node_sq = head;
        while(node_sq!=nullptr && node_sq->next!=nullptr)
        {
            node = node->next;
            node_sq = node_sq->next->next;
            if(node==node_sq)
            {
                return true;
            }
        }
        return false;
    }
};