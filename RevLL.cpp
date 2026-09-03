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
    ListNode* reverseList(ListNode* head) {
        ListNode* node = head;
        ListNode* prev;
        if(node==nullptr || node->next==nullptr)
        {
            return head;
        }
        ListNode* temp;
        if(node == head)
        {
            temp = node->next;
            node->next = nullptr;
            prev = node;
            node = temp;
        }
        while(node!=nullptr && node->next != nullptr)
        {
            temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        node->next = prev;
        return node;
    }
};