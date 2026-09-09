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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* N1 = l1;
        ListNode* N2 = l2;
        ListNode dummy;
        ListNode* tail = &dummy;
        int num = 0;
        int carry = 0;
        while(N1 != nullptr && N2 != nullptr)
        {
            num = N1->val + N2->val + carry;
            carry = num/10;
            if(num>9)
            {
                num = num%10;
            }
            tail->next = new ListNode(num);
            tail = tail->next;
            N1 = N1->next;
            N2 = N2->next;            
        }
        while(N1!=nullptr)
        {
            num = N1->val + carry;
            carry = num/10;
            if(num>9)
            {
                num = num%10;
            }
            tail->next = new ListNode(num);
            tail = tail->next;
            N1 = N1->next;
        }
        while(N2!=nullptr)
        {
            num = N2->val + carry;
            carry = num/10;
            if(num>9)
            {
                num = num%10;
            }
            tail->next = new ListNode(num);
            tail = tail->next;
            N2 = N2->next;
        }
        if(carry!=0)
        {
            tail->next = new ListNode(carry);
            tail = tail->next;
        }
        return dummy.next;
    }
};