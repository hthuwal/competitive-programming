#include<bits/stdc++.h>

using namespace std;

class Point{
public:
	int x;
	int y;
	Point()
	{
		x = 0; y =0;
	}
	Point(int x, int y)
	{
		this->x = x; this->y = y;
	}
};

class Segment{
public:
	Point p1;
	Point p2;

	Segment()
	{
		p1 = Point();
		p2 = Point();
	}
	Segment(Point a, Point b)
	{
		p1 = a;
		p2 = b;
	}
};

#define vs vector<Segment>


/**
 * Given three colinear points a, b and c
 * Check if point b lies on the segment a----c
 */
bool lies_between(Point a, Point b, Point c)
{
	bool cond_x = b.x <= max(a.x, c.x) and b.x >= min(a.x, c.x);
	bool cond_y = b.y <= max(a.y, c.y) and b.y >= min(a.y, c.y);

	if (cond_x and cond_y)
		return true;

	return false;
}


/**
 * To find orientation of ordered triplet (p, q, r). 
 * The function returns following values 
 * 0 --> p, q and r are colinear 
 * 1 --> Clockwise 
 * 2 --> Counterclockwise 
 */
int orientation(Point a, Point b, Point c)
{
	/**
	 * Idea is two compare slpes of line a---b say m1 and line b---c say m2
	 * if m1 - m2 == 0 => colinear
	 * if m1 - m2 > 0 => clockwise
	 * if m1 - m2 < 0 => anticlockwise
	 */
	int value = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);

	if(value > 0)
		return 1;
	else if(value < 0)
		return 2;
	else
		return 0;
}


bool intersect(Segment s1, Segment s2)
{
	Point a = s1.p1, b = s1.p2;
	Point c = s2.p1, d = s2.p2;
	/**
	 * Idea is that if the segmetn a---b and c--d do intersect
	 * 		then c and d lie on opposite sides of a---b => orientation of a,b,c (o1) and a,b,d (o2) should be different
	 * 		also a and b lie on opposite sides of c---d => orientation of c,d,a (o3) and c,d,b (o4) should be different
	 *
	 * In case they are colinear:
	 * 		that is o1 == o2 == o3 == o4 == 0, they intserct
	 * 			if a or b lie on the segment c---d 
	 * 			or c or d lie on the segment a---b
	 */
	
	int o1 = orientation(a, b, c);
	int o2 = orientation(a, b, d);
	int o3 = orientation(c, d, a);
	int o4 = orientation(c, d, b);

	if(o1 != o2 and o3 != o4)
		return true;
	else if(o1 == 0 and o2 == 0 and o3 ==0 and o4 == 0)
	{
		bool cond1 = lies_between(c, a, d) or lies_between(c, b, d);
		bool cond2 = lies_between(a, c, b) or lies_between(a, d, b);
		if(cond1 or cond2)
			return true;
		else 
			return false;
	}
	return false;
}	

bool compare(Segment s1, Segment s2)
{
	int x1 = max(s1.p1.x, s1.p2.x);
	int x2 = max(s2.p1.x, s2.p2.x);

	return x1 < x2;
}

int solve_dp(vs segments)
{
	int n = segments.size();
	vector<int> dp(n, 1);

	sort(begin(segments), end(segments), compare);

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(not intersect(segments[i], segments[j]))
			{
				int temp = dp[j] + 1;
				if(temp > dp[i])
					dp[i] = temp;
			}
		}
	}

	return *max_element(begin(dp),end(dp));
}
int main()
{
	int n;
	cin>>n;
	vs segments(n, Segment());

	for(int i=0;i<n;i++)
	{
		cin>>segments[i].p1.x>>segments[i].p1.y;
		cin>>segments[i].p2.x>>segments[i].p2.y;
	}

	cout<<solve_dp(segments);
}