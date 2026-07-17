#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 /* Push all digits of l1 into stack s1.
  Push all digits of l2 into stack s2. 
  While either stack is non-empty or carry exists Pop from stacks Add carry 
  Create a new node with sum % 10 
  Insert at the front Return head.*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Create two stacks
        stack<int> s1, s2;

        // Push all digits of l1 into s1
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        // Push all digits of l2 into s2
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* head = nullptr;

        // Process until both stacks are empty and no carry remains
        while (!s1.empty() || !s2.empty() || carry) {

            int sum = carry;

            // Add top of first stack if available
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            // Add top of second stack if available
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            // Create a new node with current digit
            ListNode* newNode = new ListNode(sum % 10);

            // Insert at the beginning of the answer list
            newNode->next = head;
            head = newNode;
            carry = sum / 10;
        }

        return head;
    }
};

int main() {
    Solution s;
    ListNode* l1 = new ListNode(7, new ListNode(2, new ListNode(4, new ListNode(3))));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* result = s.addTwoNumbers(l1, l2);

    // Print the result
    while (result) {
        cout << result->val;
        if (result->next) cout << " -> ";
        result = result->next;
    }
    cout << endl;

    return 0;
}