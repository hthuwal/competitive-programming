/**
 * https://www.hackerrank.com/challenges/crossword-puzzle
 */


#include<bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

char bakchodi;

/**
 * returns the x, y coordinate of the first 
 * blank found.
 *
 * If no blank found return -1, -1
 */
pi find_empty(char a[10][10])
{
	for(int i=0;i<10;i++)
	{
		for(int j=0; j<10; j++)
		{
			if(a[i][j]=='-')
				return make_pair(i, j);
		}
	}
	return make_pair(-1, -1);
}

/**
 * print the puzzle
 */
void print(char a[10][10])
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(a[i][j] == '+')
				printf("%c", bakchodi);
			else
				printf("%c", a[i][j]);
		}
		printf("\n");
	}
}

/**
 * function to copy puzzle state b to puzzle state a
 */
void copy(char a[10][10], char b[10][10])
{
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			a[i][j] = b[i][j];
}

/**
 * try to put str in the horizontal word consisiting of space at a[i][j]
 */
bool puth(char a[10][10], int i, int j, string str)
{
	
	/**Go to the left boundary**/
	while(j>=0 && a[i][j] != '+')
		j--;
	j++;

	/**try placing str character by character**/
	for(int k=0;k<str.length();k++)
	{
		if(str[k] == a[i][j+k] || a[i][j+k] == '-')
			a[i][j+k] = str[k];
		else
			return false;
	}
	return true;
}

/**
 * try to put str in the vertical word consisiting of space at a[i][j]
 */
bool putv(char a[10][10], int i, int j, string str)
{
	/**Got to the top boundary**/
	while(i>=0 && a[i][j] != '+')
		i--;
	i++;

	/**try placing str character by character**/
	for(int k=0;k<str.length();k++)
	{
		if(str[k] == a[i+k][j] || a[i+k][j] == '-')
			a[i+k][j] = str[k];
		else
			return false;
	}
	return true;
}

bool recursive(char a[10][10], vector<string> str)
{
	/**
	 * Find a space in the crossword
	 */
	pi space = find_empty(a);

	/**
	 * If no space left, puzzle complete
	 */
	if(space.first == -1)
	{
		print(a);
		return true;
	}

	/**
	 * Try to put every non used candidate for the word corresponding to this space
	 */
	for(int k=0;k<str.size();k++)
	{
		/**
		 * If this word hasn't been used
		 */
		if(str[k]!="")
		{
			char backup[10][10];
			copy(backup, a); /**backup of current state of puzzle**/

			/**
			 * try to put this word horizontally
			 */
			bool temp = puth(a, space.first, space.second, str[k]); 

			/**if can be put**/
			if(temp)
			{
				string st = str[k];
				str[k]="";

				/**try to fill the rest of the puzzle**/
				if(recursive(a, str))
					return true;
				else
				{
					/**if not possible revert state**/
					str[k] = st;
					copy(a, backup);
				}
			}
			else
				/** revert state */
				copy(a, backup);

			/**
			 * try to put this word vertically
			 */
			temp = putv(a, space.first, space.second, str[k]);
			if(temp)
			{
				string st = str[k];
				str[k]="";
				if(recursive(a, str))
					return true;
				else
				{
					str[k] = st;
					copy(a, backup);
				}
			}
			else
				copy(a, backup);
		}
	}
	return false;
}

/**
 * split a string at delimeter
 */
vector<string> split(string s, char delim)
{
	vector<string> temp;
	string str;
	for(int i=0; i<s.length();i++)
	{
		if(s[i] == delim)
		{
			temp.push_back(str);
			str = "";
		}
		else
			str += s[i];
	}
	temp.push_back(str);
	return temp;
}


int main()
{
	char a[10][10];
	vector<string> str;
	for(int i=0;i<10;i++)
		scanf("%s",a[i]);

	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			if(a[i][j]!='-')
			{
				bakchodi = a[i][j];
				a[i][j]='+';
			}
	string test;
	cin>>test;
	str = split(test, ';');
	recursive(a, str);
}