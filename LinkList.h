#ifndef LINKLIST_H
#define LINKLIST_H
#include <cstdlib>
#include <iostream>
using namespace std;
struct LinkList
{
    int data;
    LinkList *next;
};
LinkList *Create(int n)
{
    LinkList *head=new LinkList;
    head->next=NULL;
    cout<<"Please input "<<n<<" numbers(int):"<<endl;
    for (int i=n;i!=0;--i) {
        LinkList *p=new LinkList;
        cin>>p->data;
        p->next=head->next;
        head->next=p;
    }
    return head;
}
int GetElem(LinkList *head,int i,int &x)
{
    LinkList *p=head->next;
    int j=1;
    while (p&&j!=i) {
        p=p->next;
        ++j;
    }
    if (!p||j>i) {
        cout<<"Can't find it!"<<endl;
        return -1;
    }
    x=p->data;
    return x;
}
void Insert(LinkList *&head,int i,int e)
{
    LinkList *p=head;
    int j=0;
    while (p&&j!=i-1) {
        p=p->next;
        ++j;
    }
    if (!p||j>i-1) exit(EXIT_FAILURE);
    LinkList *s=new LinkList;
    s->data=e;
    s->next=p->next;
    p->next=s;
}
void Delete(LinkList *&head,int i,int &x)
{
    LinkList *p=head;
    int j=0;
    while (p->next&&j!=i-1) {
        p=p->next;
        ++j;
    }
    if (!(p->next)||j>i-1) exit(EXIT_FAILURE);
    LinkList *q=p->next;
    p->next=q->next;
    x=q->data;
    cout<<"The number deleted is "<<x<<endl;
}
void Merge(LinkList *&h1,LinkList *&h2,LinkList *&h3)
{
    LinkList *pa=h1->next;
    LinkList *pb=h2->next;
    LinkList *pc=h3=h1;
    while (pa&&pb) {
        if (pa->data<=pb->data) {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    pc->next=pa?pa:pb;
    delete h2;
}
#endif
