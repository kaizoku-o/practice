// Problem: Add two linked lists
// You are given two non-empty linked lists representing two non-negative
// integers. The digits are stored in reverse order and each of their
// nodes contain a single digit.  Add the two numbers and return it as a
// linked list.
// You may assume the two numbers do not contain any leading zero, except the
// number 0 itself.

#include "config.h"

using namespace std;

struct ListNode {
    ListNode* next;
    int val;
    ListNode(int x) { val = x; next = NULL; }
};

void print_list(ListNode* root)
{
    while (root != NULL)
    {
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}

class Solution
{
public:
    int getNextInt(ListNode** l1) {
        if (!*l1)
            return 0;
        int val = (*l1)->val;
        *l1 = (*l1)->next;
        return val;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode *ans = new ListNode(-1);
        ListNode **temp = &ans;


        while (l1 or l2 or carry) {
            int num1 = getNextInt(&l1);
            int num2 = getNextInt(&l2);

            int result = num1 + num2 + carry;

            carry = result / 10;
            result = result % 10;

            (*temp)->next = new ListNode(result);
            temp = &((*temp)->next);
        }
        ListNode* temp_2 = ans;
        ans = ans->next;

        delete temp_2;
        return ans;
    }
};



int main()
{
    ListNode* root_1 = new ListNode(5);
    print_list(root_1);

    ListNode* root_2 = new ListNode(5);
    print_list(root_2);


    Solution s;
    ListNode* result = s.addTwoNumbers(root_1, root_2);
    cout << "Result: " << endl;
    print_list(result);
    return 0;
}
