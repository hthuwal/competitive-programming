#include<iostream>
using namespace std;
struct vertex{
    char id;
    int word;
    vertex* edge[10];
};
vertex* start;
void free(vertex *hc)
{
    if(hc==NULL)
        return;
    else
    {
        for(int i=0;i<10;i++)
        {
            free(hc->edge[i]);
        }
        delete hc;
    }
}
void initialize(){
    free(start);
    start=new vertex();
    start->id=' ';
    start->word=0;
    for(int i=0;i<10;i++)
        start->edge[i]=NULL;
}
void add(string hc)
{
    vertex* temp = start;
    int n = hc.length(),x;
    for(int i = 0;i<n;i++){
        x=hc[i]-'0';
        if(temp->edge[x]==NULL){
            temp->edge[x] = new vertex();
            temp=temp->edge[x];
            temp->id=hc[i];
            if(i==n-1)
                (temp->word)++;
        }
        else
        {
            temp=temp->edge[x];
            if(i==n-1)
                (temp->word)++;
        }
    }
}

int check(string hc){
    vertex* temp = start;
    int n = hc.length(),x;
    for(int i = 0;i<n;i++){
        x=hc[i]-'0';
        if(temp->edge[x]!=NULL){
       temp=temp->edge[x];
       if(temp->word>0 && i!=n-1)
            return 0;
    }
    else
        break;
    }
    return 1;
}

int main()
{
    int t,n,flag;
    string string_array[1500];
    cin>>t;
    while(t--){
        cin>>n;
        initialize();
        for(int i=0;i<n;i++){
            cin>>string_array[i];
            add(string_array[i]);
        }
        for(int i=0;i<n;i++){
            flag=check(string_array[i]);
            if(flag==0)
                break;
        }
        if(flag==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
