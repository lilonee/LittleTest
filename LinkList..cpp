#include "LinkList.h"
int main()
{
    LinkList *L1=Create(10);
    LinkList *p1=L1;
    while (p1->next) {
        p1=p1->next;
        cout<<p1->data<<"  ";
    }
    cout<<endl;
    int a=0;
    cout<<"The number got is "<<GetElem(L1,5,a)<<endl;
    Insert(L1,5,5);
    while (p2->next) {
        p2=p2->next;
        cout<<p2->data<<"  ";
    }
    cout<<endl;
    int b=0;
    Delete(L1,5,b);
    LinkList *p3=L1;
    while (p3->next) {
        p3=p3->next;
        cout<<p3->data<<"  ";
    }
    cout<<endl;
    LinkList *L2=Create(10);
    LinkList *L3=new LinkList;
    Merge(L1,L2,L3);
    LinkList *p4=L3;
    while (p4->next) {
        p4=p4->next;
        cout<<p4->data<<"  ";
    }
    cout<<endl; 
    return 0;
}
