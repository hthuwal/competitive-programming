/**
 * https://www.spoj.com/problems/TOE2/
 *
 * Given a Tic Tac Toe Board
 * Tell whether its a valid final board state or not. Provided 'X'
 * plays first.
 *
 * Solution: Play the game with 'X' and save all final
 * board configurations (where 'X' wins, 'O' wins or no one wins.
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
Play Tic Tac Toe and save all final states
 */
void play(string grid, char player)
{
	char other_player = player == 'X' ? 'O' : 'X';

	int count = 0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(grid[index(i, j)] == '.')
			{
				count ++;
				grid[index(i, j)] = player;

				bool horz = grid[index(i,j)] != '.' and grid[index(i, j)] == grid[index(i+1, j)] and grid[index(i, j)] == grid[index(i+2, j)];
				bool verz = grid[index(i,j)] != '.' and grid[index(i, j)] == grid[index(i, j+1)] and grid[index(i, j)] == grid[index(i, j+2)];

				bool d1 = grid[index(1,1)] != '.' and grid[index(0,0)] == grid[index(1,1)] and grid[index(1,1)] == grid[index(2,2)];
				bool d2 = grid[index(1,1)] != '.' and grid[index(0,2)] == grid[index(1,1)] and grid[index(1,1)] == grid[index(2,0)];

				if(not horz and not verz and not d1 and not d2)
					play(grid, other_player);
				else // somebody won a final state
					all.insert(grid);

				grid[i*3+j] = '.';
			}
		}
	}

	// if there were no empty positions left
	// game ended with stalemate no body wins
	// a possible final state
	if(count == 0)
		all.insert(grid);

}
int main()
{
	int t;
	cin.sync_with_stdio(false);
	play(".........", 'X');

	string grid;
	cin>>grid;
	while(grid != "end")
	{
		if(all.find(grid) != all.end())
			cout<<"valid\n";
		else
			cout<<"invalid\n";
		cin>>grid;
	}
}