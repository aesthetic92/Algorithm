#include <stdio.h>
#include <string.h>  
#include <stdlib.h>  
  
#define INF 999999  
int main(int argc, char const *argv[])  
{  
    int i, j, n, m;  
    int dis[10], temp[10], u[10], v[10], w[10];  
    int check, flag = 0;  
  
    scanf("%d %d", &n, &m);  
    for(i = 1; i <= m; ++i)  
    {  
        scanf("%d %d %d", &u[i], &v[i], &w[i]);  
    }  
  
    for(i = 1; i <= n; ++i)  
    {  
        dis[i] = INF;  
    }  
    dis[1] = 0;  
  
/// Bellman-Ford算法主要代码  
    for(j = 1; j < n; ++j)     /// 最多循环n-1轮  
    {  
        for(i = 1; i <= n; ++i)  
        {  
            temp[i] = dis[i];      /// 对BellmanFord优化，有可能在n-1轮松弛之前就已经计算出最短路径，所以先备份dis数组  
        }  
  
        for(i = 1; i <= m; ++i)        /// 最核心的3句Bellman-Ford算法  
        {  
            if(dis[v[i]] > dis[u[i]] + w[i])  
            {  
                dis[v[i]] = dis[u[i]] + w[i];  
            }  
        }  
  
        check = 0;      /// 检测dis数组是否有更新  
        for(i = 1; i <= n; ++i)  
        {  
            if(temp[i] != dis[i])  
            {  
                check = 1;  
                break;  
            }  
        }  
  
        if(!check)     ///  没有更新则提前退出程序  
        {  
            break;  
        }  
    }  
  
    for(i = 1; i <= m; ++i)     /// n-1次之后最短路径还会发生变化则含有负权回路  
    {  
        if(dis[v[i]] > dis[u[i]] + w[i])  
        {  
            flag = 1;  
        }  
    }  
  
    if(flag)  
    {  
        printf("负权回路");  
    }  
    else  
    {  
        for(i = 1; i <= n; ++i)  
            {  
                printf("%d ", dis[i]);  
            }  
    }  
    printf("\n");  
  
    system("pause");  
    return 0;  
}