#include<bits/stdc++.h>
using namespace std;


/**
 * Compare two arrays of length 26
 * return true if all their corresponding elements are equal to each other
 * else return false
 */
bool test(int hash1[], int hash2[])
{
	for(int i=0;i<26;i++)
		if(hash1[i] != hash2[i])
			return false;
	return true;
}

int main()
{
	// read pattern and text
	string pattern, text;
	cin>>pattern>>text;

	// create a array which stores frequency 
	// of every letter in the pattern
	int pattern_hash[26] = {0};
	for(int i=0; i<pattern.length(); i++)
		pattern_hash[pattern[i]-'a'] ++;

	// if lenght of pattern is greater than text
	// it cannot occur in text 
	if (pattern.length() > text.length())
		cout<<"NO";
	else
	{
		// size of window to be searched is equal to the length of the pattern
		int ws = pattern.length();
		
		// create an array that stores frequency of the letters
		// in the initial window in text
		int text_hash[26] = {0};
		for(int i=0;i<pattern.length(); i++)
			text_hash[ text[i]-'a' ]++;

		bool possible = false;

		for(int i=0; i+ws-1<text.length(); i++)
		{
			// if its not the first window
			if(i!=0)
			{
				// slide the window
				
				// i-1 th letter will no longer be in window so decrease its count in hash
				text_hash[text[i-1]-'a']--; 

				// i+ws-1 th letter will now be part of the window so increase the count 
				// of that letter in hash
				text_hash[text[i+ws-1]-'a']++;
			}

			// if the hash's match 
			// the pattern and the current window are 
			// permuations of each other
			if (test(text_hash, pattern_hash))
			{
				possible = true;
				break;
			}
		}
		
		if(possible)
			cout<<"YES";
		else
			cout<<"NO";
	}	
}