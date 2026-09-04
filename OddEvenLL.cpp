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
    ListNode* oddEvenList(ListNode* head) {
        int curr_index = 0;
        int len = 0;
        ListNode* node = head;
        ListNode* tail = nullptr;
        ListNode* prev = nullptr;
        while(node!=nullptr && node->next!=nullptr)
        {
            node=node->next;
            len++;
        }
        len++;
        tail = node;
        node=head;
        while(curr_index<len && node!=nullptr && node->next!=nullptr)
        {
            if(curr_index%2!=0)
            {
                prev->next = node->next;
                tail->next = node;
                tail = node;
                node = node->next;
                tail->next = nullptr;
            }
            else
            {
                prev = node;
                node = node->next;
            }
            curr_index++;
        }
        return head;
    }
};