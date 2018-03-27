#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;

string start,endd;
map<string,int>mp;

void BFS()
{


    queue<string>q;
    q.push(start);
    mp[start]=0;



    while(!q.empty())
    {

        string temp=q.front();
        q.pop();


        for(int i=0; i<4; i++)      // this loop is if we increase by one at i-th index of the source number
        {
            string node=temp;
            node[i]=  (((node[i]-'0' +1)+10)%10)+'0' ;

            if(mp[node]==0)
            {
                mp[node]=mp[temp]+1;
                q.push(node);
            }
        }

        for(int i=0; i<4; i++)  //// this loop is if we decrease by one at i-th index of the source number
        {
            string node=temp;
            node[i]=  (((node[i]-'0' -1)+10)%10)+'0' ;

            if(mp[node]==0)
            {
                mp[node]=mp[temp]+1;
                q.push(node);
            }
        }
    }





}


string make(string str)
{


    std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());

    return str;
}



int main()
{




   int test;
   cin>>test;
   getchar();

   while(test--){

    getline(cin,start);
    start= make(start);

    getline(cin,endd);
    endd=make(endd);        // Just removed the spaces

    string str;

    int n,x;
    scanf("%d",&n);

    getchar();
    for(int i=1; i<=n; i++)
    {
        str="";
        getline(cin,str);
        str= make(str);
        mp[str]=-1;     // forbidden configurations


    }


    BFS();

    if(start==endd) printf("0\n");
    else if(mp[endd]==0) printf("-1\n");       // not reached
    else printf("%d\n",mp[endd]);
    mp.clear();

    if(test)
    getchar();


   }

    return 0;
}
