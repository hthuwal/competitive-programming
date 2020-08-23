#include <bits/stdc++.h>
using namespace std;
#define vs vector<string>

pair<int, int> horizontal(vs &grid, int x, int y) {
    int left = y;
    int right = y;
    while(left > 0 and grid[x][left-1] != '+') left --;
    while(right < 9 and grid[x][right+1] != '+') right ++;
    return {left, right-left+1};
}

pair<int, int> vertical(vs &grid, int x, int y) {
    int uptop = x;
    int bottom = x;
    while(uptop > 0 and grid[uptop-1][y] != '+') uptop --;
    while(bottom < 9 and grid[bottom+1][y] != '+') bottom ++;
    return {uptop, bottom-uptop+1};
}

bool write(vs &grid, int x, int y, int l, bool hr, string str) {
    int i, nop = 0;
    int &ri = hr != true? i : nop;
    int &ci = hr == true? i: nop;

    for(i=0;i<l;i++)
        if(grid[x + ri][y + ci] != '-' && grid[x + ri][y + ci] != str[i])
            return false;
    
    for(i=0;i<l;i++)
        grid[x + ri][y + ci] = str[i];
    return true;
}

bool solve(vector<string> &grid, vector<string> words) {
    int x=-1, y=-1;
    for(int i=0;i<10 && x==-1;i++) 
        for(int j=0;j<10;j++)
            if(grid[i][j] == '-')
                {
                    x=i;y=j;
                    break;
                }

    if(x==-1 and y==-1)
        return true;

    pair<int, int> sev = vertical(grid, x, y);
    pair<int, int> seh = horizontal(grid, x, y);
    
    for(string cword: words) {
        vs nwords;
        for(string word: words)
            if(word != cword)
                nwords.push_back(word);
        vs backup_grid = grid;
        
        if(cword.length() == sev.second) {
            bool possv = write(grid, sev.first, y, sev.second, false, cword);
            if(possv)
            {
                if(solve(grid, nwords))
                    return true;
                else
                    grid = backup_grid;
            }
        }

        if(cword.length() == seh.second) {
            bool possh = write(grid, x, seh.first, seh.second, true, cword);
            if(possh)
            {
                if(solve(grid, nwords))
                    return true;
                else
                    grid = backup_grid;
            }
        }
    }
    return false;
}

char sanitize(vs &grid) {
    char fucker = '+';
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            if(grid[i][j] != '-') {
                fucker = grid[i][j];
                grid[i][j] = '+';
            }
    return fucker;
}

void desanitize(vs &grid, char shit) {
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            if(grid[i][j] == '+')
                grid[i][j]=shit;
}

// Complete the crosswordPuzzle function below.
vector<string> crosswordPuzzle(vector<string> grid, string words) {
    char fuck = sanitize(grid);
    vector<string> words_list;
    string word = "";
    for(int i=0;i<words.length();i++)
    {   
        if(words[i] == ';') {
            words_list.push_back(word);
            word.clear();
        }
        else
            word += words[i];
    }   
    words_list.push_back(word);
    solve(grid, words_list);
    desanitize(grid, fuck);
    return grid;
}


int main()
{
    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}
