#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;


map<int,int>mp;
vector<int>start,endd;

void clearr()
{
    mp.clear();
    start.clear();
    endd.clear();
}

int create(vector<int>temp)
{
    int num=0;
    for(int i=0;i<temp.size();i++)
        num=num*10+temp[i];

    return num;
}


void BFS()
{

    queue<vector<int> >q;
    q.push(start);
    mp[create(start)]=0;



    while(!q.empty())
    {

        vector<int>temp=q.front();
        q.pop();


        for(int i=0; i<4; i++)      // this loop is if we increase by one at i-th index of the source number
        {
             vector<int> node=temp;

             node[i]= ((node[i]+1)+10)%10;

             if(mp[create(node)]==0)
             {
                 //printf("->%d\n")
                 mp[create(node)]= mp[create(temp)]+1;
                 q.push(node);

             }




        }


        for(int i=0; i<4; i++)  //// this loop is if we decrease by one at i-th index of the source number
        {
            vector<int> node=temp;

             node[i]= ((node[i]-1)+10)%10;

             if(mp[create(node)]==0)
             {
                 mp[create(node)]= mp[create(temp)]+1;
                 q.push(node);

             }
        }
    }





}




int main()
{



   int test;
   cin>>test;
   getchar();



   while(test--){

    int x;
    for(int i=0;i<4;i++) { scanf("%d",&x); start.push_back(x);  }
    for(int i=0;i<4;i++) { scanf("%d",&x); endd.push_back(x);  }


    int n;
    scanf("%d",&n);


    for(int i=1; i<=n; i++)
    {
        vector<int>temp;
        for(int j=0;j<4;j++)
        {
            scanf("%d",&x);
            temp.push_back(x);
        }

        int num= create(temp);
        mp[num]=-1;     // forbidden configurations

      //  printf("num= %d\n",num);

    }


    BFS();

    if(start==endd) printf("0\n");
    else if(mp[create(endd)]==0) printf("-1\n");       // not reached
    else printf("%d\n",mp[create(endd)]);

    clearr();



   }

    return 0;
}
