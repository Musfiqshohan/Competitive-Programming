#include<bits/stdc++.h>
using namespace std;
vector<string>str;
int l,n;
int a[300][300], vis[300];

string make_large(string s)
{
    int i=0;
    while(s[i])
    {
        if(s[i]>=97 && s[i]<=122) s[i]=s[i]-32;
        i++;
    }
    return s;
}
int ret_index(string s)
{
    int index=-1,i;
    for(i=0; i<l ; i++)
    {
        if(str[i]==s)
            index=i;
    }
    if(index==-1)
    {
        str.push_back(s);
        index=i;
        l++;
    }
    return index;

}

int dfs(int node)
{
    int total=0,i;

    for(i=0; i<=n; i++)
    {
        if(a[node][i]==1)
        {
            if(vis[i]==-1)
            {
                vis[i]=1;
             //   printf("xx%d %d\n",node,i);
                total = max ( total , 1+ dfs(i));
               //  printf("total= %d\n",total);
                vis[i]=-1;
            }
        }
    }


    return total;

}
int main()
{

    memset(vis,-1,sizeof vis);


    int i,j, index1,index2;
    string s1,s2,x;
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        cin>>s1>>x>>s2;

        s1= make_large(s1);
        s2= make_large(s2);
      // cout<<s1<<" "<<s2<<endl;
        index1=ret_index(s2);
        index2= ret_index(s1);

        a[index1][index2]=1;
        a[index2][index1]=1;

        //printf("%d %d\n",index1,index2);

    }

//    for(i=0; i<n; i++)
//    {
//        for(j=0; j<n; j++) printf("%d ",a[i][j]);
//        printf("\n");
//    }

    vis[0]=1;
    cout<<dfs(0)+1<<endl;





    return 0;
}
