/**
 * https://www.spoj.com/problems/TOE1/
 *
 * Given a Tic Tac Toe Board
 * Tell whether its a valid board or not. Provided 'X'
 * plays first.
 *
 * Solution: Play the game with 'X' and save all correct
 * board configurations.
 */

#include<bits/stdc++.h>

using namespace std;
unordered_set<string> all;

void print(string grid)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			int r = i*3 + j;
			cout<<grid[r];
		}
		cout<<endl;
	}
	cout<<"\n\n";
}

int index(int i, int j)
{
	return (j % 3) + (i % 3) * 3;
}

/*
Play Tic Tac Toe and save all possible states
 */
void play(string grid, char player)
{
	char other_player = player == 'X' ? 'O' : 'X';

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(grid[index(i, j)] == '.')
			{
				grid[index(i, j)] = player;
				all.insert(grid);

				bool horz = grid[index(i,j)] != '.' and grid[index(i, j)] == grid[index(i+1, j)] and grid[index(i, j)] == grid[index(i+2, j)];
				bool verz = grid[index(i,j)] != '.' and grid[index(i, j)] == grid[index(i, j+1)] and grid[index(i, j)] == grid[index(i, j+2)];

				bool d1 = grid[index(1,1)] != '.' and grid[index(0,0)] == grid[index(1,1)] and grid[index(1,1)] == grid[index(2,2)];
				bool d2 = grid[index(1,1)] != '.' and grid[index(0,2)] == grid[index(1,1)] and grid[index(1,1)] == grid[index(2,0)];

				if(not horz and not verz and not d1 and not d2)
					play(grid, other_player);

				grid[i*3+j] = '.';
			}
		}
	}

}
int main()
{
	int t;
	cin.sync_with_stdio(false);
	all.insert(".........");
	play(".........", 'X');

	cin>>t;
	while(t--)
	{
		string grid, temp;
		for(int i=0;i<3;i++)
		{
			cin>>temp;
			grid += temp;
		}

		if(all.find(grid) != all.end())
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
}