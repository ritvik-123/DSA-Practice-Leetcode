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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* node1 = list1;
        ListNode* node2 = list2;
        ListNode Dummy;
        ListNode* result = &Dummy;
        while(node1!=nullptr && node2!=nullptr)
        {
            if(node1->val < node2->val)
            {
                result->next = new ListNode(node1->val);
                result = result -> next;
                node1 = node1->next;
            }
            else
            {
                result -> next = new ListNode(node2->val);
                result = result -> next;
                node2 = node2->next;
            }
        }
        if(node1!=nullptr)
        {
            result -> next = node1;
        }
        if(node2!=nullptr)
        {
            result -> next = node2;
        }
        return Dummy.next;
    }
};