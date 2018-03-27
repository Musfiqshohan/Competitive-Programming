#include <stdio.h>
#include <map>
using namespace std;
map<long long, int> mp;
int l[10000], w, r;
int main(){
    int n, x, y, ans = 0;
    scanf("%d", &n);
    for (x = 0; x < 10; x++){
        for (y = x + 1; y < 10; y++){
            w = r = 0;
            if (x && x <= n) l[w++] = x;
            if (y && y <= n) l[w++] = y;
            while (r < w){
                long long t = l[r];
                if (t * 10 + x <= n) l[w++] = t * 10 + x;
                if (t * 10 + y <= n) l[w++] = t * 10 + y;
                r++;
            }
            for (r = 0; r < w; r++){
                if (mp.count(l[r]) == 0){
                    ans++;
                    mp[l[r]] = 1;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
