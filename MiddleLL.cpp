/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        int length = 0;
        ListNode* node = head;
        while(node->next!=NULL)
        {
            length++;
            node = node->next;
        }
        length++;
        node = head;
        int curr = 0;
        while(curr<length/2)
        {
            node = node->next;
            curr++;
        }
        return node;
    }
};