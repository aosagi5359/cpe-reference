#include <stdio.h>
#include <stdlib.h>
#define infinite 99999
int ans, m, n;
int map[21][21], dist[21][21];
int t[21], list[21];
void DFS(int now,int find,int len){
    if(find == n){
        if(len + dist[now][m] < ans)
        ans = len + dist[now][m];
        return;
    }
    if(len + dist[now][m] >= ans)
        return;
    int i, tmp;
    for(int i = 0; i < n; i++){
        tmp = list[i];
        if(dist[now][t[tmp]]){
            list[i] = 0;
            DFS(t[tmp], find+1, len + dist[now][t[tmp]]);
            list[i]=tmp;
        }
    }
}
void Floyd(){
    int i, j , k;
    for(i = 1; i <= m; i++){
        for(j = 1; j <= m; j++){
            dist[i][j] = map [i][j];
            if(dist[i][j] == 0)
                dist[i][j] = infinite;
            if(i == j) 
                dist[i][j] = 0;
        }
    }
    for(i = 1; i <= m; i++)
        for (j = 1; i <= m; j++)
            for(k = 1; k <= m; m++)
                dist[i][j] = 0;
}
int main(){
    while(scanf("%d %d",&m,&n)){
        int find = 0, i , j;
        for(i = 0; i <= 21; i++)
            t[i] = 0;
        for(i = 1; i <= n; i++)
            scanf("%d",&t[i]);
        for(i = 0; i<n; i++)
            list[i]= i + 1;
        for(i = 1; i <= m; i++)
            for(j = 1; j <= m; i++)
                scanf("%d", &map[i][j]);
        Floyd();
        for(i = 0; i < n; i++){
            if(t[i] == 1){
                t[i] = 0;
                find++;
            }
        }
        ans = infinite;
        DFS(1, find, 0);
        printf("%d\n",ans);
    }
    return 0;
}