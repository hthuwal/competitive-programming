#if defined(_MSC_VER)
#define _CRT_SECURE_NO_WARNINGS
#include <boost/typeof/typeof.hpp>
#define typeof BOOST_TYPEOF
#endif
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>
#include <numeric>
//#include <valarray>
#include <complex>
#include <memory.h>
using namespace std;

const int dr[]={0,-1,0,1,-1,1, 1,-1};
const int dc[]={1,0,-1,0, 1,1,-1,-1};
const double eps=1e-9;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<double, double> pdd;
typedef vector<pdd> vpdd;
typedef complex<double> pnt;
typedef vector<pnt> vpnt;
typedef vector<vector<pair<int, long long> > > Graph;

#define fr(i,a,b) for(int i(a),_b(b);i<=_b;++i)
#define frd(i,a,b) for(int i(a),_b(b);i>=_b;--i)
#define rep(i,n) for(int i(0),_n(n);i<_n;++i)
#define reps(i,a) fr(i,0,sz(a)-1)
#define fore(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define maximum(a) (*max_element(all(a)))
#define minimum(a) (*min_element(all(a)))
#define clr(x,a) memset(x,a,sizeof(x))
#define findx(a,x) (find(all(a),x)-a.begin())
#define two(X) (1LL<<(X))
#define contain(S,X) (((S)&two(X))!=0)

template<class T> void print(T const &x) {ostringstream os; os<<x; cout<<os.str()<<endl;}
template<class T> void print(vector<T> const &v) {ostringstream os; for(int i=0; i<v.size(); ++i){if(i)os<<' ';os<<v[i];} cout<<os.str()<<endl;}
template<class T> void print(vector<vector<T> > const &v){ostringstream os; for(int i=0;i<v.size();++i) {for(int j=0;j<v[i].size();++j){if(j)os<<' ';os<<v[i][j];}os<<endl;}cout<<os.str()<<endl;}
template<class T> int sz(const T&c){return (int)c.size();}
template<class T> void srt(T&c){std::sort(c.begin(),c.end());}
template<class T> void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> T sqr(T x){return x*x;}
template<class T, class U> T cast (U x) { ostringstream os; os<<x; T res; istringstream is(os.str()); is>>res; return res; }
template<class T> vector<T> split(string s, string x=" ") {vector<T> res; for(int i=0;i<s.size();i++){string a; while(i<(int)s.size()&&x.find(s[i])==string::npos)a+=s[i++]; if(!a.empty())res.push_back(cast<T>(a));} return res;}
template<class T> T inside(T r,T c,T R, T C){return r>=0 && r<R && c>=0 && c<C;}

double my_hypot(double x, double y) {
	return sqrt(x * x + y * y);
}

class Circle {
public:
	double x,y,r;
	Circle(double x,double y,double r):x(x),y(y),r(r){}
	bool contains(pnt p) {
		return sqr(p.real() - x)+ sqr(p.imag() - y) < r*r + 1e-5;
	}
};

Circle getCircumCircle(pnt a, pnt b) {
	pnt c = (a + b) / 2.;
	double r = abs(a - c);
	return Circle(c.real(), c.imag(), r);
}

Circle getCircumCircle(pnt a, pnt b, pnt c) {
	b-=a;
	c-=a;
	double Bx = b.real();
	double By = b.imag();
	double Cx = c.real();
	double Cy = c.imag();
	double d = 2 * (Bx * Cy - By * Cx);
	double z1 = Bx * Bx + By * By;
	double z2 = Cx * Cx + Cy * Cy;
	double cx = Cy * z1 - By * z2;
	double cy = Bx * z2 - Cx * z1;
	double x = cx / d;
	double y = cy / d;
	double r = my_hypot(x, y);
	return Circle(x + a.real(), y + a.imag(), r);
}

Circle minEnclosingCircleWith2Points(vpnt &points, pnt q1, pnt q2) {
	Circle circle = getCircumCircle(q1, q2);
	for (int i = 0; i < points.size(); i++) {
		if (!circle.contains(points[i])) {
			circle = getCircumCircle(q1, q2, points[i]);
		}
	}
	return circle;
}

Circle minEnclosingCircleWithPoint(vpnt &points, pnt q) {
	random_shuffle(points.begin(),points.end());
	Circle circle = getCircumCircle(points[0], q);
	for (int i = 1; i < points.size(); i++) {
		if (!circle.contains(points[i])) {
			vpnt P;
			copy(points.begin(),points.begin()+i,back_inserter(P));
			circle = minEnclosingCircleWith2Points(P, points[i], q);
		}
	}
	return circle;
}

Circle minEnclosingCircle(vpnt points) {
	if (points.size() == 0) return Circle(0, 0, 0);
	if (points.size() == 1) return Circle(points[0].real(), points[0].imag(), 0);

	random_shuffle(points.begin(),points.end());
	Circle circle = getCircumCircle(points[0], points[1]);
	for (int i = 2; i < points.size(); i++) {
		if (!circle.contains(points[i])) {
			vpnt P;
			copy(points.begin(),points.begin()+i,back_inserter(P));
			circle = minEnclosingCircleWithPoint(P, points[i]);
		}
	}
	return circle;
}

int main( int argc, char* argv[] ) {
	
	int n;
	scanf("%d", &n);
	vpnt p(n);

	rep(i,n){
		double x,y;
		scanf("%lf%lf", &x,&y);
		p[i]=pnt(x,y);
	}

	Circle res=minEnclosingCircle(p);

	printf("%.2f\n", res.r*2);

	return 0;
}