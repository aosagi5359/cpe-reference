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
void