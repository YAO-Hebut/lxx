
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
int n,m,s,mp[1005][1005],j,path[3000],vis[1005];
//n，m代表点的个数，s代表开始顶点，边的条数，mp储存路径，j储存路径数，path储存具体路径，vis标记是否访问
void dfs(int start){//start代表开始的点
    int i;
    for(i = 1; i <= n; i++){
        if(mp[start][i]==1&&!vis[i]){//如果这个店之间是联通的（看mp[start][i]是否为1），并且这个点没有走过
            vis[i] = 1;//标记为1
            path[j] = i;//记录路径
            j++;
            dfs(i);//递归到下一个点
            path[j] = start;//这里可能有点矛盾，标记的作用是不走重复的点，但是这里很明显又回到了上一个的点，是因为当无路可走时，要想回到最初起点，必须
            j++;//回到上一个点，但这个并不会造成混乱，因为这样写规定了，回溯时可以回到上一点，也就是每一次这能会上一点，原路返回，不可能返回几步又去走
        }       //其他的路，这也就是为什么这里我们没有让vis[i]=0，因为每一步都是落实的，都要记录下来
    }
}
int main(){
    memset(path,0,sizeof(path));
    memset(vis,0,sizeof(vis));
    memset(mp,INF,sizeof(mp));
    int i;
    scanf("%d%d%d",&n,&m,&s);
    for(i = 0; i < m; i++){
        int u,v;
        scanf("%d%d",&u,&v);
        mp[u][v] = 1;
        mp[v][u] = 1;
    }
    path[0] = s;
    j++;
    vis[s] = 1;
    dfs(s);//利用深搜
    int flag = 1;//遍历后如果全都走过了，vis应该全部标记为1，所以通过这个条件判断能不能全部点亮灯
    for(i = 1; i <= n; i++){
        if(vis[i]==0){
            flag = 0;
            break;
        }
    }
    if(!flag){//如果不能点亮所有灯输出路径，最后加0
        for(i = 0; i < j; i++){
            if(i==0)printf("%d",path[i]);
            else printf(" %d",path[i]);
        }
        printf(" 0");//在循环结束后输出0
    }
    else{//全部点亮，直接输出路径
        for(i = 0; i < j; i++){
            if(i==0)printf("%d",path[i]);
            else printf(" %d",path[i]);
        }
    }
    puts("");
    return 0;
}