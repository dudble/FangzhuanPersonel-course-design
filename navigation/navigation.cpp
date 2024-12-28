#include<iostream>
#include<string.h>
using namespace std;
class Graph{
private:
    struct Pre
    {
        char point;
        string road;
        int kilo;
    }pre[100];
    //虽然我写的是pre，但这里存的是每个点走最短路时下一条边的信息（

    class Edges{
        public:
            struct Edge{
                int v,w;
                string name;
            };
            int length=0;
            Edge *edge = new Edge[100];
            void add(int v,int w,string name){
                length++;
                edge[length]={v,w,name};
            }
            
    };
    Edges *edges = new Edges[100];
    //其实可以定义一个变量n，将这里的100换为n，并另写一个函数，用以在图超限时更新n，使图容量增大。其他出现100的地方同理

public:
    
    int size = 0;

    ~Graph(){
        delete[] edges;
    }


    //新边的建立
    void build(int from,int w,int to,string name)
    {
        if(from > size) size=from;
        edges[from].add(to,w,name);
    }


    //dijkstra找最短路
    void minroad(char start,char end){
        int n = size;
        if(start==end){
            cout << "不要原地兜圈" << endl;
            return ;
        }
        if(start<'a'||end<'a'||start>='a'+size||end>='a'+size)
        {
            if(start<'a'||start>'a'+size) cout << "起点不存在" << endl;
            if(end<'a'||end>'a'+size) cout << "终点不存在" << endl;
            return ;
        }

        
        
        int d[100],vis[100];
        for(int i=0;i<=n;i++){ 
            vis[i]=0;
            d[i]=0x3f3f3f3f;
            pre[i].point=-1;
        }
        d[end-'a'+1]=0;
        for(int i=1;i<=n;i++){
            int u=0;
            for(int j=1;j<=n;j++){
                if(!vis[j]&&d[j]<d[u]) u=j;
            }
            vis[u]=1;

            for(int j=1;j<=edges[u].length;j++){
                auto ed=edges[u].edge[j];
                if(d[ed.v]>d[u]+ed.w){ 
                    d[ed.v]=d[u]+ed.w;
                    pre[ed.v].point = u;
                    pre[ed.v].road = ed.name;
                    pre[ed.v].kilo = ed.w;
                }
            }
        }

        int cnt = 0;
        for(int i=start-'a'+1;pre[i].point!=end-'a'+1;i=pre[i].point)
        {
            if(pre[i].point==-1){
                cout << "暂无道路通行" << endl;
                return ;
            }
            cnt++;
        }
        printf("开始出发，全程共经过%d处红绿灯。",cnt);
        for(int i=start-'a'+1;i!=end-'a'+1;i=pre[i].point){
             
            cout << "沿" << pre[i].road << "行驶" << pre[i].kilo << "KM。";
            if(pre[i].point==end-'a'+1) break;
            if(pre[i].road!=pre[pre[i].point].road){
                
                cout << "通过路口后，进入" << pre[pre[i].point].road << "。";
            }
            if(pre[i].road==pre[pre[i].point].road){
                cout << "通过路口后，继续沿" << pre[i].road << "行驶" << pre[pre[i].point].kilo << "KM。";
            }
        }
        cout << "到达目的地，本次导航结束，欢迎下次使用！" << endl;
    }
}; 


int main(){
    Graph graph;
    graph.build(1,400,2,"changjiang road");
    graph.build(1,3,3,"harukaze road");
    graph.build(1,20,9,"changjiang road");
    graph.build(2,400,1,"changjiang road");
    graph.build(2,5,8,"taian road");
    graph.build(3,3,1,"harukaze road");
    graph.build(3,7,4,"tenka road");
    graph.build(4,7,3,"tenka road");
    graph.build(4,2,5,"tenka road");
    graph.build(4,8,6,"minan road");
    graph.build(4,10,8,"qingjinag road");
    graph.build(5,2,4,"tenka road");
    graph.build(5,3,8,"huzhu road");
    graph.build(5,10,7,"worker road");
    graph.build(6,8,4,"minan road");
    graph.build(7,10,5,"worker road");
    graph.build(8,5,2,"taian road");
    graph.build(8,10,4,"qingjiang road");
    graph.build(8,3,5,"huzhu road");
    graph.build(9,20,1,"changjiang road");
    
    int num = 0;
    do{
        cout << "---~*~欢迎使用本导航~*~---" << endl;
        cout << "----输入1查询最短路线-----" << endl;
        cout << "-----输入2构建新路线------" << endl;
        cout << "------输入3退出程序------" << endl;

        cin >> num;
        char start,end;
        if(num==1){
            cout << "您从何地出发" << endl;
            cin >> start;
            cout << "您欲去往何地" << endl;
            cin >> end;
            graph.minroad(start,end);
        }
        if(num==2){
            string name;
            int kilo;
            cout << "请依次输入路线的起点 里程 终点 名称" << endl;
            cin >> start >> kilo >> end >> name;
            graph.build(start-'a'+1,kilo,end-'a'+1,name);
            graph.build(end-'a'+1,kilo,start-'a'+1,name); 
            cout << "新路径生成完成" << endl;
        }
    }
    while(num!=3);

    return 0;
}