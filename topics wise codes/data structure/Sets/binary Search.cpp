// set::lower_bound/upper_bound
#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;


int main ()
{
  std::set<int> myset;
  std::set<int>::iterator itlow,itup;

//  for (int i=10; i>=1; i--) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90
//
//  itlow=myset.lower_bound (30);                //       ^
//  itup=myset.upper_bound (60);                 //                   ^
//
//  myset.erase(itlow,itup);

    int n,x;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&x), myset.insert(x);

    scanf("%d",&x);


    itlow= myset.lower_bound(x);
    cout<<itlow - myset.begin() <<endl;

                       // 10 20 70 80 90


//  std::cout << "myset contains:";
//  for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
//    std::cout << ' ' << *it;
//  std::cout << '\n';

  return 0;
}
