#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3, *T;
        int count = 0;
        int sum, carry=0;
        //考虑两个数长度不一样长
        while(l1 != NULL | l2 != NULL) {
            // carry 是进位
            sum = carry;
            carry = 0;
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            if(sum >= 10) {
                carry = 1;
                sum -= 10;
            }
            ListNode tem(sum);
            T = &tem;
            if(count == 0)
                l3 = T;
            T = T->next;
            count+=1;
        }
        return l3;
    }
};


int main() {
    ListNode *l1, *l2;
    ListNode t11(2);
    ListNode t12(4);
    ListNode t13(3);
    t11.next = &t12;
    t12.next = &t13;
    l1 = & t11;
    ListNode t21(5);
    ListNode t22(6);
    ListNode t23(4);
    t21.next = &t22;
    t22.next = &t23;
    l2 = & t21;
    Solution so;
    ListNode *l3 = so.addTwoNumbers(l1,l2);
    return 0;
}

