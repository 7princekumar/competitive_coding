//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode *p3 = NULL, *ans = NULL;
        int sumValue = 0, carry = 0;
        while(p1 != NULL || p2 != NULL) {
            carry = 0;
            if(p1 != NULL){
                sumValue += p1->val;
                p1 = p1->next;
            }
            if(p2 != NULL){
                sumValue += p2->val;
                p2 = p2->next;
            }
            carry = sumValue / 10; // sumValue = 18 -> carry is 1, and sumValue is 8
            sumValue %= 10;
            ListNode* temp = new ListNode(sumValue);
            sumValue = carry;
            if(ans == NULL) {
                ans = p3 = temp;
            }else{
                p3->next = temp;
                p3 = temp;
            }
        }
        if(carry != 0) {
            p3->next = new ListNode(carry);
        }
        return ans;
    }
};