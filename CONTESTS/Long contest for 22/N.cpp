zzz// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>
#include<bits/stdc++.h>
using namespace std;

/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

map<string, int>mp;
vector<string>vec;
void permute(char *a, int l, int r)
{


   int i;
   if (l == r){

     for(int i=0;i<strlen(a);i++)
     {
         if((a[i])==(a[i+1])) return ;
     }


     string str(a);
     if(mp[str]==0){


    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='a')
            printf("    ");
        else printf("%c",str[i]);
    }
    puts("");
     //vec.push_back(str);


     }

     mp[str]=1;
   }
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}

/* Driver program to test above functions */
int main()
{
    char str[] = "aaabbcc";
    int n = strlen(str);
    permute(str, 0, n-1);

    sort(vec.begin(), vec.end());
    cout<<vec.size()<<endl;
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<endl;
    }
    return 0;
}
