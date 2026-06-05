#include <iostream>
#include <cmath>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* t = head;
        int count = 0;

        while (t != NULL) {
            count++;
            t = t->next;
        }

        t = head;
        count--;

        int n = 0;

        while (t != NULL) {
            n = n + (t->val * pow(2, count));
            t = t->next;
            count--;
        }

        return n;
    }
};

int main() {
    // Create linked list: 1 -> 0 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);

    Solution obj;
    cout << "Decimal Value: " << obj.getDecimalValue(head) << endl;

    return 0;
}