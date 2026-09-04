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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* node = head;
        ListNode* prev = nullptr;
        while(node != nullptr && node -> next != nullptr)
        {
            length++;
            node = node->next;
        }
        length++;
        int index_to_remove = length - n;
        int curr = 0;
        node = head;
        if(index_to_remove == 0)
        {
            head = node->next;
            return head;
        }
        while(node!=nullptr && curr<index_to_remove)
        {
            prev = node;
            node = node->next;
            curr++;
        }
        prev->next = node->next;
        return head;
    }
};