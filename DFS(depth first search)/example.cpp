#include <stdio.h>
#include <stdlib.h>
#define infinite 99999 //定義無限遠距離
int ans, m, n;  // m為寶藏點藏總數, n為寶藏總數
int map[21][21], dist[21][21];  //map 為路徑資訊, dist 為各點之間的距離
int t[21], list[21];    //t 為寶藏點資訊, list 為記錄行經寶藏與否
void DFS(int now,int find,int len){ //DPS函式進行最點路徑搜尋，now為目前所在的點，find為目前找到的寶藏數量，len 為目前路徑長度
    if(find == n){                  //判斷行經所有寶藏後到到達終點是否為最短路徑，若為最短路徑，則是目前最好的答案
        if(len + dist[now][m] < ans)
        ans = len + dist[now][m];
        return;
    }
    if(len + dist[now][m] >= ans)   //若是目前路徑長度已經超過目前最小，則停止搜尋
        return;
    int i, tmp;
    for(int i = 0; i < n; i++){ //透過記錄各點寶藏的list對所有可能的排序進行搜尋
        tmp = list[i];
        if(dist[now][t[tmp]]){
            list[i] = 0;
            DFS(t[tmp], find+1, len + dist[now][t[tmp]]);
            list[i]=tmp;
        }
    }
}
void Floyd(){                           //Floyd函式的功能是將輸入得到的迷宮資訊map轉換成迷宮中各點之間的距離，
    int i, j , k;                       //如dist[i][j] = 5，表示迷宮中的點i到點j的距離為5。
    for(i = 1; i <= m; i++){            //值若為infinite，則表示點i無法到達點j。
        for(j = 1; j <= m; j++){        //計算各點距離可用Floyd演算法
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
                if(dist[j][i]+dist[i][k]<dist[j][k])
                    dist[j][k] = dist[j][i] + dist[i][k];
}
int main(){
    while(scanf("%d %d",&m,&n)){    //取得m與n
        int find = 0, i , j;
        for(i = 0; i <= 21; i++)    //初始化寶藏列表t
            t[i] = 0;
        for(i = 1; i <= n; i++)     //取得n個寶藏點
            scanf("%d",&t[i]);
        for(i = 0; i<n; i++)        //建立選擇寶藏清單
            list[i]= i + 1;
        for(i = 1; i <= m; i++)
            for(j = 1; j <= m; i++)
                scanf("%d", &map[i][j]);    //取得迷宮map
        Floyd();    //建立各點之距離dist
        for(i = 0; i < n; i++){      //如果起點驗有寶藏，直接找到並從t去除
            if(t[i] == 1){
                t[i] = 0;
                find++;
            }
        }
        ans = infinite; //初始化ans
        DFS(1, find, 0); //進行DFS
        printf("%d\n",ans); //捯到最短路徑
    }
    return 0;
}