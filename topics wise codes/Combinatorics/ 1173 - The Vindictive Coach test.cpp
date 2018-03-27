    #include <iostream>
    #include <algorithm>
    #include <cstring>

    using namespace std;


    int f(char str[])
    {
        for(int i=1;i<strlen(str)-1;i+=2)
        {
            if(str[i]<str[i-1]  || str[i]<str[i+1]) return 0;
        }

        return 1;

    }

    int main() {
        char anagrama[13]= { '1','2', '3', '4' , '5','6', '7'}; //  ,'8', '9'
    	//cin>>anagrama;
    int len = strlen(anagrama);
    sort(anagrama, anagrama+len);
    do {

        if( f(anagrama)==1 )
        cout << anagrama << endl;
    } while (next_permutation(anagrama, anagrama+len));
    	return 0;
    }
