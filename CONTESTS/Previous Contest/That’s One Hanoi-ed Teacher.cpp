#include<bits/stdc++.h>
using namespace std;
stack<int>p[5];
void print()
{
    if(p[1].empty()==1) printf("0");
    else
    {
        for (std::stack<int> dump = p[1]; !dump.empty(); dump.pop())
            std::cout << dump.top()<<" ";
    }
    puts(" ");

    if(p[2].empty()==1) printf("0");
    else
    {
        for (std::stack<int> dump = p[2]; !dump.empty(); dump.pop())
            std::cout << dump.top()<<" ";
    }
    puts(" ");

    if(p[3].empty()==1) printf("0");
    else
    {
        for (std::stack<int> dump = p[3]; !dump.empty(); dump.pop())
            std::cout << dump.top()<<" ";
    }

    puts(" ");
}
int cnt=0;
void hanoi(int n, int init, int dest, int spare)
{

    if(n==0) {   return; }

    hanoi(n-1,init,spare,dest);
    printf("Move %d from %d to %d\n",n, init, dest);
    cnt++;
    cout<<"cnt "<<cnt<<endl;
    p[init].pop();
    p[dest].push(n);
    print();

    hanoi(n-1, spare, dest, init);

}

int main()
{
    //stack<int>p2;
    // stack<int>p3;

    int n,i;
    scanf("%d",&n);
//    for(i=1; i<=n; i++)
//    {
//        scanf("%d",&x);
//        p1.push(x);
//    }
//    scanf("%d",&n);
//    for(i=1; i<=n; i++)
//    {
//        scanf("%d",&x);
//        p2.push(x);
//    }
//    scanf("%d",&n);
//    for(i=1; i<=n; i++)
//    {
//        scanf("%d",&x);
//        p3.push(x);
//    }

    for(i=n; i>=1; i--) p[1].push(i);
    print();
    hanoi(n,1,3,2);

    return 0;
}
