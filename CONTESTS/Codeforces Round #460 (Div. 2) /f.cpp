// C program to print all permutations with duplicates allowed
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

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
map<string,int>mp;
void permute(char a[], int l, int r)
{
    int i;
    if (l == r)
    {
        string temp(a);
        if(mp.find(temp)==mp.end()){

            for(int i=0;i<temp.size()-1;i++)
            {
                if(temp[i]==temp[i+1])
                    return;
            }
            printf("%s\n", a);
            mp[temp]=1;

        }

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
    char str[] = "aabbcc";
    int n = strlen(str);
    permute(str, 0, n-1);
    cout<<mp.size()<<endl;
    return 0;
}
