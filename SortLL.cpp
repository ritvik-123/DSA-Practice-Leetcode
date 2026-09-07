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
    ListNode* sortList(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        //find mid
        ListNode* fast = head;
        ListNode* mid = head;
        while(fast!=nullptr && fast->next != nullptr && fast->next->next!=nullptr)
        {
            fast = fast->next->next;
            mid = mid->next;
        }
        //break into half
        ListNode* second = mid->next;
        mid->next = nullptr;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(second);
        //merge both list
        return mergeList(l1,l2);
    }
    ListNode* mergeList(ListNode* head1, ListNode* head2)
    {
        ListNode* node1 = head1;
        ListNode* node2 = head2;
        ListNode dummy;
        ListNode* curr = &dummy;
        while(node1 != nullptr && node2 != nullptr)
        {
            if(node1->val < node2->val)
            {
                curr->next = node1;
                node1 = node1->next;
            }
            else
            {
                curr->next = node2;
                node2 = node2->next;
            }
            curr = curr->next;
        }
        if(node1!= nullptr)
        {
            curr->next = node1;
        }
        else
        {
            curr->next = node2;
        }
        return dummy.next;
    }
};