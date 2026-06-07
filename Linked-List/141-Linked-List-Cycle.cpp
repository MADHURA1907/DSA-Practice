#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        vector<ListNode* >arr;
        ListNode* t=head;
        while(t!=NULL)
        {
            for(int i=0;i<arr.size();i++)
            {
                if(t->next==arr[i])
                {
                    return true;
                }
            }
            arr.push_back(t);
            t=t->next;

        }
        return false;
    }
};

int main()
{
    Solution obj;
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    
    head->next = second;
    second->next = third;
    third->next = second; // Creates a cycle

    bool result = obj.hasCycle(head);
    
    cout << "Has Cycle: " << (result ? "Yes" : "No") << endl;

    return 0;
}