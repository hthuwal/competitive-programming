#include<iostream>
#include<vector>

using namespace std;

template<class T> class mat
{
	private:
		vector<vector<T> > m;
	public:
		mat(){};

		mat(int row,int col)
		{
			m.assign(row,vector<T>(col));
		}

		void assign(int row,int col)
		{
			m.assign(row,vector<T>(col));
		}

		int rowsize() const
		{
			return m.size();
		}

		int colsize() const
		{
			if(m.size()==0)
				return 0;
			else 
				return m[0].size();
		}

		vector<T> &operator[](int i)
		{
			return m[i];
		}

		mat<T> operator * (mat<T> b)
		{
			mat<T> temp(this->rowsize(),b.colsize());

			for(int i=0;i<temp.rowsize();i++)
			{
				for(int j=0;j<temp.colsize();j++)
				{
					for(int k=0;k<b.rowsize();k++)
					{
						temp[i][j]+=(*this)[i][k]*b[k][j];
					}
				}
			}
			return temp;
		}

		mat<T> operator %(int MOD)
		{
			mat<T> temp(this->rowsize(),this->colsize());
			for(int i=0;i<this->rowsize();i++)
			{
				for(int j=0;j<this->colsize();j++)
				{
					temp[i][j]=m[i][j]%MOD;
				}
			}
			return temp;
		}
		void clear()
		{
			m.clear();
		}
};

template<class T> T power(T n,long long m,int MOD)
{
	if(m==1)
		return n;
	T x=power(n,m/2,MOD);
	if(m%2==0)
		return (x*x)%MOD;
	else
		return (((x*x)%MOD)*n)%MOD;
}
int main()
{
	mat<long long int> in(26,26);
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			cin>>in[i][j];

	const int MOD = 1000000007;
	int t;
	cin>>t;
	while(t--)
	{
		char endChar;
		long long int l;
		cin>>endChar>>l;
		mat<long long int> ans = power(in,l-1,MOD);
		long long int ways =0;
		for(int i=0;i<ans.colsize();i++)
		{
			ways+=ans[i][endChar-'a'];
		}
		cout<<ways%MOD<<endl;
	}
}