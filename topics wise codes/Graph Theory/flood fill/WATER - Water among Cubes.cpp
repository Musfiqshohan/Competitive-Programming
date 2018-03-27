#include<bits/stdc++.h>
using namespace std;
vector<int>heap;
int cub[109][109], filled[109][109],  vis[109][109];
int dir_row[4]= {-1, 1, 0,0};
int dir_col[4]= { 0, 0,-1,1};
int taken[10009];
int n,m,total=0;

struct data
{
    int row, col;
};

void print()
{
    for(int i=0; i<heap.size(); i++)
        printf("%d ",heap[i]);

}

void BFS(data source,int target)
{
    queue<data>q;

    q.push(source);
    vis[source.row][source.col]=target;

    //printf("suck %d\n",target);
    while(!q.empty())
    {
        data u= q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            data node= {u.row+dir_row[i],  u.col+dir_col[i]};

            if((vis[node.row][node.col]!=target) &&  (node.row>=0 && node.row<n && node.col>=0 && node.col<m) )
            {
                //if(vis[node.row][node.col]==0  )
                //{
                    if(cub[node.row][node.col]<=target)
                    {
                       // printf("%d %d -> %d %d w=    %d\n",u.row, u.col,node.row, node.col,cub[node.row][node.col]);

                        if(vis[node.row][node.col]==0)
                        total+= target- cub[node.row][node.col];
                       // printf("total= %d\n",total);
                        vis[node.row][node.col]=target;

                        q.push({node.row, node.col});
                    }

                    else
                    {
                        if(taken[cub[node.row][node.col]]==0)
                        {
                            heap.push_back(cub[node.row][node.col]);
                            push_heap(heap.begin(), heap.end(), greater<int>());
                            taken[cub[node.row][node.col]]=1;
                        }
                    }
                //}


            }

        }
    }


}
void heapify_the_border()
{
    int i;
    for(i=0; i<m; i++)
    {
        if(taken[cub[0][i]]==0)
        {
            heap.push_back(cub[0][i]);
            //printf("cub=%d  is taken= %d\n",cub[0][i],taken[cub[0][i]] );
        }

        taken[cub[0][i]]=1;
    }

    for(i=0; i<m; i++)
    {
        if(taken[cub[n-1][i]]==0)
        {
            heap.push_back(cub[n-1][i]);
            //printf("cub=%d  is taken= %d\n",cub[n-1][i],taken[cub[n-1][i]] );

        }
        taken[cub[n-1][i]]=1;
    }

    for(i=0; i<n; i++)
    {
        if(taken[cub[i][0]]==0)
            {heap.push_back(cub[i][0]);
            // printf("cub=%d  is taken= %d\n",cub[i][0],taken[cub[i][0]] );
            }
        taken[cub[i][0]]=1;
    }


    for(i=0; i<n; i++)
    {
        if(taken[cub[i][m-1]]==0)
        {
            heap.push_back(cub[i][m-1]);
           //  printf("fuck cub=%d  is taken= %d\n",cub[i][m-1],taken[cub[i][m-1]] );
        }
        taken[cub[i][m-1]]=2;
    }

    make_heap(heap.begin(),heap.end(), greater<int>());
    //print();
}

void flood_from_border(int target)
{
    int i;
    for(i=0; i<m; i++)
    {
        if(vis[0][i]!=target && cub[0][i]<=target )  //cub[0][i]==target &&
            BFS({0,i},target);
    }

    for(i=0; i<m; i++)
    {
        if(vis[n-1][i]!=target && cub[n-1][i]<=target)  // && vis[n-1][i]==0  //cub[n-1][i]==target &&
            BFS({n-1,i},target);
    }

    for(i=0; i<n; i++)
    {
        if(vis[i][0]!=target && cub[i][0]<=target)  // && vis[i][0]==0  //cub[i][0]==target &&
            BFS({i,0},target);
    }

    for(i=0; i<n; i++)
    {
        if(vis[i][m-1]!=target && cub[i][m-1]<=target)  // && vis[i][m-1]==0 //cub[i][m-1]==target &&
            BFS({i,m-1},target);
    }

}

int main()
{
    int t=0,test;
    scanf("%d",&test);

    while(t++<test){
    int i,j;
    scanf("%d %d",&n,&m);

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            scanf("%d",&cub[i][j]);
    }

    heapify_the_border();


   // print();

    // flood_from_border(3);
    total=0;
    while(heap.size()!=0)
    {
        int target=heap.front();
        pop_heap(heap.begin(), heap.end(), greater<int>());
        heap.pop_back();

       // printf("Fucking target= %d\n",target);
        flood_from_border(target);
       // printf("total= %d\n",total);

    }
      cout<<total<<endl;

      memset(vis,0,sizeof vis);
      memset(taken,0,sizeof taken);
      memset(cub,0,sizeof cub);
      memset(filled,0,sizeof filled);
      heap.clear();

    }

    return 0;
}
