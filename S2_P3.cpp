#include <bits/stdc++.h>

using namespace std;
#define rep0(i,n)   for(int i=0;i<n;++i)

/// Sort an array according to another array.

void S2P3()
{

 int n1,n2;
 cout << "Enter Size of array one :";cin>>n1;
 int*Arry1=new int[n1];
 cout << "Enter items of array :";
 rep0(i,n1)
 {
     cin>>Arry1[i];
 }

 cout << "Enter Size of array two :";cin>>n2;
 int*Arry2=new int[n2];
 cout << "Enter items of array :";
 rep0(i,n2)
 {
     cin>>Arry2[i];
 }


 int k=0;
 int cnt_idx=0;
 rep0(j,n2)
 {
       rep0(i,n1)
       {
         if(Arry2[j]==Arry1[i])
        {
            swap(Arry1[i],Arry1[k]);
            ++k;
            ++cnt_idx;
        }
       }
 }
 sort(Arry1+cnt_idx,Arry1+n1);

 cout << "\n";
 cout << "output :  A1[] = { ";
 rep0(i,n1)
 {
     cout << Arry1[i]<< " " ;
 }

 cout << "}\n";



}

int main()
{
    S2P3();
    return 0;
}
