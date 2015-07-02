#include <iostream>
#include "Sqlist.h"
using namespace std;
int main()
{
    SqList L1=Init();
    SqList L2=Init();
    SqList L3=Init();
    cout<<L1.length<<endl;
    int a1[ ]={1,2,3,4,5,6,7,8,9,10};
    int a2[ ]={11,12,13,15,16,17,18};
    L1.elem=a1;
    L2.elem=a2;
    L2.length=7;
    L1.length=10;
    for (int i=0;i!=10;++i)
        cout<<L1.elem[i]<<"  ";
    cout<<endl;
    for (int i=0;i!=7;++i)
        cout<<L2.elem[i]<<"  ";
    cout<<endl;
    cout<<L1.length<<endl;
    Insert(L1,5,11);
    for (int i=0;i!=L1.length;++i)
        cout<<L1.elem[i]<<"  ";
    cout<<endl;
    cout<<L1.length<<endl;
    int b=0;
    Delete(L1,5,b);
    for (int i=0;i!=L1.length;++i)
        cout<<L1.elem[i]<<"  ";
    cout<<endl;
    cout<<L1.length<<endl;
    Merge(L1,L2,L3); 
    for (int i=0;i!=L3.length;++i)
        cout<<L3.elem[i]<<"  ";
    cout<<endl;  
}
