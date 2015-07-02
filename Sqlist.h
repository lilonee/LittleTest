#ifndef SQLIST_H
#define SQLIST_H
#include <cstdlib>
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10
struct SqList
{
    int *elem;
    int length;
    int list_size;
};
SqList Init()
{
    SqList L;
    L.elem=new int[LIST_INIT_SIZE*sizeof(int)];
    if (!L.elem)  exit (EXIT_FAILURE);
    L.length=0;
    L.list_size=100;
    return L;
}
void Insert(SqList &L,int i,int e)
{
    if (i<1 ||i>L.length+1) exit (EXIT_FAILURE);
    if (L.length>=L.list_size) {
        SqList Ln;
        Ln.elem=(int*)realloc(L.elem,(L.list_size+LIST_INCREMENT)*sizeof(int));
        if (!Ln.elem)  exit (EXIT_FAILURE);
        L.elem=Ln.elem;
        L.list_size+=LIST_INCREMENT;
        }
     int *q=&(L.elem[i-1]);
     for (int *p=&(L.elem[L.length-1]);p>=q;--p)
         *(p+1)=*p;
     *q=e;
     ++L.length;
}
void Delete(SqList &L,int i,int &e)
{
    if (i<1 ||i>L.length+1) exit (EXIT_FAILURE);
    int *p=&(L.elem[i-1]);
    e=*p;
    int *q=L.elem+L.length-1;
    for (++p;p<=q;++p) *(p-1)=*p;
    --L.length;
}
void Merge(SqList La,SqList Lb,SqList &Lc)
{
    int *pa=La.elem;
    int *pb=Lb.elem;
    Lc.length=La.length+Lb.length;
    Lc.elem=new int[Lc.list_size*sizeof(int)];
    if (!Lc.elem) exit(EXIT_FAILURE);
    int *pc=Lc.elem;
    int *pa_last=La.elem+La.length-1;
    int *pb_last=Lb.elem+Lb.length-1;
    while (pa<=pa_last && pb<=pb_last) {
        if (*pa<=*pb) { 
            *pc=*pa;
            pa++;
            pc++;
        }
        else {
            *pc=*pb;
            pb++;
            pc++;
        }
     }
     while (pa<=pa_last) {
         *pc=*pa;
         pa++;
         pc++;
     }
     while (pb<=pb_last) {
         *pc=*pb;
         pb++;
         pc++;
     }
}
#endif
