#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1=headA;
        
        while(t1!=NULL)
        {
            ListNode* t2=headB;
            while(t2!=NULL)
            {
                if(t1==t2)
                {
                    return t1;
                }
                t2=t2->next;
            }
            t1=t1->next;
        }
        
        return NULL;
    }
};

int main()
{
    Solution s;
    ListNode* headA=new ListNode(1);
    headA->next=new ListNode(2);
    headA->next->next=new ListNode(3);
    
    ListNode* headB=new ListNode(4);
    headB->next=headA->next;
    
    cout<<s.getIntersectionNode(headA,headB)->val<<endl;;
    return 0;
}