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
    void deleteNode(ListNode* node) {
        //make current node same as next node
        node->val = node->next->val;
        //make next to next node as current's next node
        node->next = node->next->next;
    }
};