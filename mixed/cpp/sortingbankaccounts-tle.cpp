#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define x 1000000;
using namespace std;
class bankaccount{

    public:string a,b,c,d,e,f;
           int count;

    public:

    bankaccount(){
        this->count=0;
    }

    bankaccount(string a,string b,string c,string d,string e,string f){
        this->a=a;
        this->b=b;
        this->c=c;
        this->d=d;
        this->e=e;
        this->f=f;
        this->count=1;
    }

    int compare(bankaccount ba){
        if(atoi((this->a).c_str())<atoi((ba.a).c_str()))
            return 0;
        else if(atoi((this->a).c_str())>atoi((ba.a).c_str()))
            return 1;
        else{
            if(atoi((this->b).c_str())<atoi((ba.b).c_str()))
                return 0;
            else if(atoi((this->b).c_str())>atoi((ba.b).c_str()))
                return 1;
            else{
                if(atoi((this->c).c_str())<atoi((ba.c).c_str()))
                    return 0;
                else if(atoi((this->c).c_str())>atoi((ba.c).c_str()))
                    return 1;
                else{
                    if(atoi((this->d).c_str())<atoi((ba.d).c_str()))
                        return 0;
                    else if(atoi((this->d).c_str())>atoi((ba.d).c_str()))
                        return 1;
                    else{
                        if(atoi((this->e).c_str())<atoi((ba.e).c_str()))
                            return 0;
                        else if(atoi((this->e).c_str())>atoi((ba.e).c_str()))
                            return 1;
                        else{
                            if(atoi((this->f).c_str())<atoi((ba.f).c_str()))
                                return 0;
                            else if(atoi((this->f).c_str())>atoi((ba.f).c_str()))
                                return 1;
                            else{
                                (this->count)++;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
};

void print(bankaccount ba[],int n){
 for(int i=0;i<n;i++){
        string hc = ba[i].a+" "+ba[i].b+" "+ba[i].c+" "+ba[i].d+" "+ba[i].e+" "+ba[i].f+" ";
        cout<<hc<<" "<<ba[i].count<<endl;
        if(ba[i].count>1){
            i=i-1+ba[i].count;
        }
    }
    printf("\n");
}
void merge(bankaccount a[],int low,int mid,int upper){

    bankaccount temp[upper-low+1];

    int i,j,k;

    for(i=low,j=mid+1,k=0;i<=mid&&j<=upper;){
        if(a[i].compare(a[j])==0){
            temp[k]=a[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        temp[k]=a[i];
        k++;
        i++;
    }
    while(j<=upper){
        temp[k]=a[j];
        j++;
        k++;
    }
    for(i=0;i<k;i++){
        a[low+i]=temp[i];
    }
}

void mergesort(bankaccount a[],int low, int upper){
    if(low<upper){
        int mid=(low+upper)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,upper);
        merge(a,low,mid,upper);
    }
}

int main(){
    int t,i,n;
    string a,b,c,d,e,f;
    bankaccount ba[110000];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            cin>>a>>b>>c>>d>>e>>f;
            ba[i]=bankaccount(a,b,c,d,e,f);
        }
        mergesort(ba,0,n-1);
        print(ba,n);

    }
}
