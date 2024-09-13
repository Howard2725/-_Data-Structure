/*������������һ������ڵ�Ķ������£� struct ListNode { int val; ListNode* next; }; ����Ҫ����������������������N����0<=N<=100)��
����������ϲ�Ϊһ��������������ϲ�������ÿ���ڵ��ֵ��Ҫ��:ʹ�ýṹ����ɡ�

��������ʽ��������������������һ��������������ĳ���N1��N2���ڶ���������зֱ������һ����ڶ���������ÿ���ڵ��ֵ��
������˳�����롣���ĳ��������Ϊ0������Ӧ�в���Ҫ�������ݡ�

�������ʽ�����Ϊһ�У��Կո����������������˳�������������������Ϊ�������������NULL����

KeyWord(s) that Must be Used
struct

KeyWord(s) that Mustn't be Used
[ ]

���������롿
0 1
1
1 2
1
2 3
3 3
1 3 5
2 4 6

�����������
1
1 2 3
1 2 3 4 5 6

*/

#include<iostream>  
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}

};

struct List {
    ListNode* head = nullptr;

    void insert(int x) {

        ListNode* n = new ListNode(x);

        if (head == nullptr || head->val >= x) {
            n->next = head;
            head = n;
        }
        else {
            ListNode* current = head;
            while (current->next != nullptr && current->next->val < x) {
                current = current->next;
            }
            n->next = current->next;
            current->next = n;
        }
    }

     
    void printList() {
        ListNode* current = head;   
        while (current != nullptr) { 
            cout << current->val << " ";
            current = current->next;  
        }
        cout << endl;
    }
    static ListNode* PlusLists(ListNode* l1, ListNode* l2) {
          
        ListNode sentinel(0);
        ListNode* current = &sentinel;
  
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            }
            else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

         
        if (l1 != nullptr) {
            current->next = l1;
        }
        if (l2 != nullptr) {
            current->next = l2;
        }

         
        return sentinel.next;
    }

    void PlusWith(List* other) {
        head = PlusLists(head, other->head);
    }
};

 
int main() {
    int a, b;
    while (cin >> a) {
        cin >> b;
        List* l1 = new List;
        for (int i = 0; i < a; i++) {
            int temp;
            cin >> temp;
            l1->insert(temp);
        }


        List* l2 = new List;
        for (int i = 0; i < b; i++) {
            int temp;
            cin >> temp;
            l2->insert(temp);
        }
        l1->PlusWith(l2);
        l1->printList();
    }
}