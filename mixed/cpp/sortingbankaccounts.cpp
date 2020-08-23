#include<iostream>
using namespace std;
class bankaccount{

    public:string a;
           int count;

    public:

    bankaccount(){
        this->count=1;
    }
    bankaccount(string hc){
        this->a=hc;
        this->count=1;
    }

    int compare(bankaccount ba){
        if((this->a)>(ba.a))
            return 1;
        else if((this->a)<(ba.a))
            return 0;
        else
        {
            (this->count)++;
            return 0;
        }
    }
};

void print(bankaccount ba[],int n){
 for(int i=0;i<n;i++){
        cout<<ba[i].a<<" "<<ba[i].count<<endl;
        if(ba[i].count>1){
            i=i-1+ba[i].count;
        }
    }
    cout<<endl;
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
    char temp;
    string a;
    bankaccount ba[110000];
    cin>>t;;
    while(t--){
        cin>>n;
        cin.ignore();
        for(i=0;i<n;i++){
            getline(cin,a);
            ba[i]=bankaccount(a);
        }
        mergesort(ba,0,n-1);
        print(ba,n);

    }
}
