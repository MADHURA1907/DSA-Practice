#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* t=head;
        while(t && t->next)
        {
            if(t->val==t->next->val)
            {
                ListNode* curr=t->next;
                t->next=curr->next;
                delete curr;
            }
            else
            {
                t=t->next;
            }
        }
        return head;
    }

    void printList(ListNode* head) {
        ListNode* temp = head;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    // Create list: 1->1->2->3->3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    Solution s;
    head = s.deleteDuplicates(head);

    s.printList(head);

    return 0;
}

