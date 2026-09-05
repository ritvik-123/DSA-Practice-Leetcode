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
    bool isPalindrome(ListNode* head) {
        int length = 0;
        int midi = 0;
        int curr = 0;
        ListNode* node = head;
        ListNode* mid = nullptr;
        //find length to find mid
        while(node!=nullptr&&node->next!=nullptr)
        {
            node = node->next;
            length++;
        }
        length++;
        //place the pointer at mid
        midi = length/2;
        node = head;
        while(node!=nullptr && curr<midi)
        {
            node = node->next;
            curr++;
        }
        mid = node;
        node = head;
        //reverse everything after/from mid
        ListNode* cur = mid;
        ListNode* prev = nullptr;
        ListNode* temp = nullptr;
        curr = 0;
        while (cur != nullptr)
        {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        curr = 0;
        while(head!=nullptr && prev!=nullptr)
        {
            if(head->val == prev->val)
            {
                head = head->next;
                prev = prev->next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};