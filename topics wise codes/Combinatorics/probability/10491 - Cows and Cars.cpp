#include<bits/stdc++.h>
using namespace std;

int main()
{
    double cows,cars,shows;
    while(scanf("%lf %lf %lf",&cows, &cars, &shows)==3){
   // cin>>cows>>cars>>shows;

    double tot= cows+cars;
    double sum= cars/tot  * (cars-1.0)/(tot-shows-1.0);
    sum+= cows/tot * cars/(tot-shows-1);

    printf("%.5f\n",sum);

    }


    return 0;
}
