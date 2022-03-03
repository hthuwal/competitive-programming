/**not valid for similar value**/
#include<iostream>
using namespace std;
int size;

class course{
	public:
		int id;
		int students;
		int a,b;
		int z;

		course(){
			this->a=0;
			this->b=0;
			this->students=0;
			updatez();
		}

		void updatez(){
			this->z=(this->students)*((this->a)+(this->b));
		}
		void updatestudent(int iq){
			this->students++;
			if(this->a==0)
				this->a=iq;
			else if(this->b==0)
				this->b=iq;
			else{
				this->a=this->b;
				this->b=iq;
			}
			updatez();
		}

		void copy(course b){
			this->setid(b.getid());
			this->setstudents(b.getstudents());
			this->seta(b.geta());
			this->setb(b.getb());
			this->setz(b.getz());
		}

		int getid(){
			return this->id;
		}
		int getz(){
			return this->z;
		}
		int getstudents(){
			return this->students;
		}
		int geta(){
			return this->a;
		}
		int getb(){
			return this->b;
		}
		void setstudents(int students){
			this->students=students;
		}
		void seta(int a){
			this->a =a;
		}
		void setb(int b){
			this->b =b;
		}
		void setz(int z){
			this->z=z;
		}
		void setid(int id){
			this->id = id;
		}
};

void min_heapify(course a[],int i,int n){
	int left = 2*i;
	int right =2*i+1;
	int smallest;
	smallest=i;
	if(left<=n && a[left].getz() < a[i].getz())
		smallest=left;
	if(right<=n && a[right].getz() < a[smallest].getz())
		smallest =right;
	if(smallest==i && (a[left].getz() == a[i].getz() || a[right].getz() == a[smallest].getz())){
		if(left<=n && a[left].getid() < a[smallest].getid())
			smallest=left;
		if(right<=n && a[right].getid() < a[smallest].getid())
			smallest =right;
	}
	if(smallest!=i){
		course temp;
		temp.copy(a[smallest]);
		a[smallest].copy(a[i]);
		a[i].copy(temp);
		min_heapify(a,smallest,n);
	}
}

void build_minheap(course a[],int n){
	for(int i=n/2;i>=1;i--){
		min_heapify(a,i,n);
	}
}

int main()
{
	course a[100005];
	int i,c,p,n,iq;
	cin>>c>>p>>n;
	for(i=1;i<=n;i++){
		cin>>iq;
		a[i].updatestudent(iq);
	}
	for(i=1;i<=c;i++){
		a[i].setid(i);
	}
	build_minheap(a,c);
	for(i=1;i<=p;i++){
		cin>>iq;
		cout<<a[1].getid()<<" ";
		a[1].updatestudent(iq);
		min_heapify(a,1,c);
	}
}
