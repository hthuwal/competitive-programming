/**
 * https://www.hackerrank.com/challenges/magic-square-forming/problem
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * Class representing a 3x3 matrix
 */
class Square{
private:
	int mat[3][3];
public:
	/**
	 * Constructor: convert flat representation 
	 * to mat
	 */
	Square(vector<int> arr)
	{
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				mat[i][j] = arr[3*i+j];
	}

	/**
	 * Check if it is a magic square or not
	 */
	bool isMagic()
	{
		//  n(n^2+1)/2
		int magicNum = 15;

		// sum of each row
		for(int i=0;i<3;i++)
		{
			int sum = 0;
			for(int j=0;j<3;j++) sum += mat[i][j];
			if(sum != magicNum)
				return false;
		}


		// sum of each col
		for(int j=0;j<3;j++)
		{
			int sum = 0;
			for(int i=0;i<3;i++) sum += mat[i][j];
			if(sum != magicNum)
				return false;
		}

		// sum of diagonals
		int sum = 0;
		for(int i=0;i<3;i++)
			sum += mat[i][i];

		if(sum != magicNum)
			return false;
				
		// sum of diagonals
		sum = 0;
		for(int i=0;i<3;i++)
			sum += mat[i][2-i];

		if(sum != magicNum)
			return false;
				
		return true;
	}

	void print()
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
				cout<<mat[i][j]<<"\t";
			cout<<endl;
		}
	}

	// to find difference between two squares
	friend int operator-(const Square &a, const Square &b);
};

int operator-(const Square &a, const Square &b)
{
	int ans = 0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			ans += abs(a.mat[i][j] - b.mat[i][j]);
	return ans;
}

/**
 * Find all possible magic squares
 */
vector<Square> find_all_magic()
{
	vector<int> arr(9, 0);
	vector<Square> magic_squares;

	for(int i=1;i<=9;i++)
		arr[i-1]=i;
	
	// next possible squares
	do{
		Square sq(arr);
		if(sq.isMagic())
			magic_squares.push_back(sq);
	}while(next_permutation(begin(arr), end(arr)));

	return magic_squares;
}

int main()
{
	vector<Square> magic_squares = find_all_magic();
	vector<int> arr(9, 0);
	for(int i=0;i<9;i++)
		cin>>arr[i];

	Square sq(arr);

	int ans = INT_MAX;
	for(auto msq: magic_squares)
	{
		int temp = sq - msq;
		if(temp < ans)
			ans = temp;
	}
	cout<<ans<<endl;
}