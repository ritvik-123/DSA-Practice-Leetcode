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
    ListNode* deleteMiddle(ListNode* head) {
        int length = 0;
        ListNode* node = head;
        ListNode* prev = nullptr;
        while(node != nullptr && node -> next != nullptr)
        {
            length++;
            node = node->next;
        }
        length++;
        int index_to_remove = length/2;
        int curr = 0;
        node = head;
        if(length <= 1)
        {
            return nullptr;
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