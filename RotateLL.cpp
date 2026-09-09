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
    ListNode* rotateRight(ListNode* head, int k) {
        int curr = 0;
        ListNode* node = head;
        if(node==nullptr || node->next == nullptr)
        {
            return head;
        }
        int len = 0;
        while(node!=nullptr)
        {
            len++;
            node = node->next;
        }
        if(len<k)
        {
            k = k % len;
        }
        node = head;
        while(curr<k)
        {
            ListNode* prev = nullptr;
            while(node->next!=nullptr)
            {
                prev = node;
                node = node->next;
            }
            prev->next = nullptr;
            node->next = head;
            head = node;
            curr++;
        }
        return head;
    }
};