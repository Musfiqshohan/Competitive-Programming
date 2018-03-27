#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;

int main()
{
// initializing 1st container
    vector<int> arr1 = { 1, 4, 6, 3, 2 };

    // initializing 2nd container
    vector<int> arr2 = { 6, 2, 5, 7, 1 };

    // declaring resultant container
    vector<int> arr3(5);
//    arr3.push_back(-1);
//    arr3.push_back(-1);

    // sorting initial containers
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    // using merge() to merge the initial containers
    merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(),  arr3.begin());

    // printing the resultant merged container
    cout << "The container after merging initial containers is : ";

    for (int i = 0; i < arr3.size(); i++)
        cout << arr3[i] << " ";
}
