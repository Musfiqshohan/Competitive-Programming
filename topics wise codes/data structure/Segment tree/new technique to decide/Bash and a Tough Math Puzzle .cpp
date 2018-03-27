#include<bits/stdc++.h>
#define i64 long long
#define inf 1000000000000000000
using namespace std;

map<string,int>mp;

void init()
{
    mp["<table>"]=3;
    mp["</table>"]=-3;
    mp["<tr>"]=2;
    mp["</tr>"]=-2;
    mp["<td>"]=1;
    mp["</td>"]=-1;

}


vector<int>vec,vec2;
void process(string str)
{
    string ret;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='<')
        {
            ret="";
            while(str[i]!='>'  && i<str.size())
                ret+=str[i], i++;

            ret+=str[i];

           // cout<<ret<<endl;
           // cout<<mp["<table>"]<<endl;

            vec.push_back(mp[ret]);

        }

    }


//    for(int i=0;i<vec.size();i++)
//        printf("%d ",vec[i]);




}




int main()
{
    init();
  //  freopen("input.txt","r",stdin);

    string str;
    char ara[6009];
    while((scanf("%s",&ara))!=EOF)
        str+=ara;

   process(str);





    for(int i=0;i<vec.size();i++){

        if(vec[i]<0) continue;
        if(vec[i]!=2  && vec[i]!=-2)
            vec2.push_back(vec[i]);

   }

//    for(int i=0;i<vec2.size();i++){
//
//        printf("%d ",vec2[i]);
//   }


    vector<int>tot;

   for(int i=0;i<vec2.size();i++)
   {
    if(vec2[i]==3)
    {
        int cnt=0;
        i++;
        while(vec2[i]==1)
         cnt++,i++;

        tot.push_back(cnt);
        i--;

    }


   }



   sort(tot.begin(),tot.end());

   for(int i=0;i<tot.size();i++){

    if(i) printf(" ");

    printf("%d",tot[i]);

    }

    puts("");


}

