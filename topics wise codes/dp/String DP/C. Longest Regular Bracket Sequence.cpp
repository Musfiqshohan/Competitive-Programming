#include<bits/stdc++.h>
using namespace std;

string str;
struct info
{
    char bra;
    int pos;
};

int c[1000008], d[1000009];

int main()
{
    cin>>str;

    stack<info>stk;

    int i=0,mx=-1;
    while(str[i]=='(')
    {
        stk.push({'(', i});
        i++;
    }

    for(  ; str[i]; i++)
    {

        //  cout<<i<<endl;

        if(str[i]=='(')
        {
            stk.push( {'(',i } );
        }

        else
        {
            // cout<<i<<endl;
            if(stk.empty() )
            {
                d[i]=c[i]=-1;
                // cout<<i<<" "<<c[i]<<endl;

            }


            else if(stk.top().bra=='(')
            {
                info tp= stk.top();
                stk.pop();

                d[i]=  tp.pos;
                c[i]= tp.pos;


                if(str[tp.pos-1]==')')
                {
                    if( c[ tp.pos -1 ] !=-1 )
                        c[i]= c[ tp.pos -1];

                }

                mx= max(mx, i-c[i]+1);

            }
        }

    }


    int cnt=0;
    for(int i=0; str[i]; i++)
    {
        if(str[i]==')' && c[i]!=-1 &&  (i-c[i]+1)==mx)//
        {
            cnt++;
          //  cout<<i<<endl;
        }
    }


    if(mx==-1) printf("0 1\n");
    else
        cout<<mx<<" "<<cnt<<endl;


}
