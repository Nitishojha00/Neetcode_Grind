class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end())
            return 0;

        
        queue<string>q;
        q.push(beginWord);
        int n = wordList.size();
        int m = beginWord.size();
        vector<bool>vis(n);
        int cnt = 1;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto word = q.front();
                q.pop();
                for(int i=0;i<n;i++)
                {
                    if(vis[i]) continue;
                    // we show all the words with exactly one changes according to it
                    int change = 0;
                    for(int j=0;j<m;j++)
                    {
                        if(word[j]!=wordList[i][j]) change++;
                        if(change>1) break;
                    }

                    if(change==1)
                    {
                        if(wordList[i]==endWord)  return cnt+1;
                        vis[i] = 1;
                        q.push(wordList[i]);
                    }
                }
            }
                cnt++;
        }

        return 0;
    }
};
