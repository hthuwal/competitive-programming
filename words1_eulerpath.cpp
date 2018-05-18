#include <cstdio>
#include <cstring>
#include <vector>
/**
 * Graph containing 26 vertices a to z
 * think of the alphabets as nodes of the graph. Now connect the first and 
 * the last alphabet of each string by and edges. 
 */
int list[27][27];

/**
 * Initializes Graph to Null Graph before every iteration 
 */
void init()
{
    for(int i=0;i<27;i++)
        for(int j=0;j<27;j++)
            list[i][j]=0;
}
/**
 * Absolute Value
 * @param  a integer
 * @return   absolute value of a
 */
int abs(int a)
{
    return (a>0?a:(a*-1));
}
/**
 * Add edge to the graph from node a to b
 * @param a starting vertex of edge
 * @param b end vertex of edge
 */
void addedge(char a,char b)
{
    list[a-'a'][b-'a']++;
}
/**
 * Calculate the Indegree and outdegree of the nodes
 * in the adjacency matrix representation.
 * After completion of the code:
 * the list[i][27] = the outdegree of ith node
 * the list[27][i] = the indegree of ith node
 */
void calcdegree()
{
    for(int i=0;i<26;i++)
    {
        int sumr=0;
        int sumc=0;
        for(int j=0;j<26;j++) 
        {
            sumr+=list[i][j];
            sumc+=list[j][i];
        }
        list[i][26]=sumr;
        list[26][i]=sumc;
    }
    
}
/**
 * Prints the adjacency matrix of the graph
 */
void print()
{
    printf("  ");
    for(int i=0;i<27;i++)
        printf("%c ",'a'+i);
    printf("\n");
    for(int i=0;i<27;i++)
    {
        printf("%c ",'a'+i);
        for(int j=0;j<27;j++)
            printf("%d ",list[i][j]);
        printf("\n");
    }

}

/**
 * Modified dfs that traverses every edge and deletes it
 * after traversing it. So that every edge is traversed once
 * If graph has a euler path, after modified dfs the graph must
 * become a null graph
 * @param s source vertex
 */
void modified_dfs(int s)
{
    for(int i=0;i<26;i++)
    {
        if(list[s][i]!=0)
        {
            list[s][i]--;
            modified_dfs(i);
        }
    }
}

/**
 * Checks if graph is empty or not
 * @return true if graph is empty else false
 */
bool checkifgraphempty()
{
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            if(list[i][j]!=0)
                return false;
    return true;
}

int main()
{
    int t,n;
    char a[1111];
    freopen("in.txt","r",stdin);
    for(scanf("%d",&t);t--;)
    {
        init();
        for(scanf("%d",&n);n--;)
        {
            scanf("%s",a);
            int l = strlen(a);
            addedge(a[0],a[l-1]);
        }
        calcdegree();
        // print();
        /**
         * there can be two cases:
         * 1. Exactly two nodes in the graph have |inDeg[a]−outDeg[a]|=1|inDeg[a]−outDeg[a]|=1.
         *    if you enter a node , you also must exit it (you use two edges once you enter a node) unless that node is the start or the end of the ordering).
         * 2. All the nodes have inDeg[a]==outDeg[a]. (The starting node of the path and the ending are the same).
         * 	  If none of the above, then the answer is already no euler path is not possible.
         */
        int node[2];
        int k=0;
        bool flag=true;
        for(int i=0;i<26;i++)
        {
            if(list[i][26]!=list[26][i])
            {
                if(abs(list[i][26]-list[26][i])!=1)
                {
                    flag=false;
                    break;
                }
                else if(k==2)
                {
                    flag=false;
                    break;
                }
                else
                    node[k++]=i;
            }
        }
        // printf("Flag:%d\nK:%d\na:%c\nb:%c\n",flag,k,node[0]+'a','a'+node[1]);
        
        int s;
        if(!flag) // if none of the two cases satisfy answer is already no
            printf("The door cannot be opened.\n");
        else
        {   
        	//if second condition satisfy then any node having an outgoing edge can be treated as a source node 
            if(k==0)
            {
                for(int i=0;i<26;i++)
                    if(list[i][26]>0)
                    {
                        s=i;
                        break;
                    }
            }
            else // if first condition satisfy than the node having outdegree greater than indegree is the source node
            {
                s = node[0];
                if(list[s][26]+1==list[26][s])
                    s=node[1];
            }
            /*
            do modified_dfs
             */
            modified_dfs(s);
            // print();
            /*
            check if graph is null graph after modified_dfs 
            if graph empty => euler path exists
            else => euler path doesnt exists
             */
            if(checkifgraphempty())
                printf("Ordering is possible.\n");
            else
                printf("The door cannot be opened.\n");
        }
    }
}