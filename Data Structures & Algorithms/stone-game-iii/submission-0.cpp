class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        bool turn = 1;
        int i=0;
        int a = 0 , b = 0;
        int n = stoneValue.size();
        while(i<n)
        {
            vector<int>v(3);
            for(int j=0;j<3;j++)
            {
                if(i+j<n)
                  v[j]+=stoneValue[i+j];
            }

            int sum = 0;
            if(v[0]>(max(v[1],v[2])))
                {
                    sum = v[0];
                    i++;
                }
            else if(v[1]>(max(v[0],v[2])))
                {
                    sum += v[1];
                    i+=2;
                }
            else 
                {
                    sum += v[2];
                    i+=3;
                }

            if(turn) a+=sum;
            else b+=sum;
            turn = !turn;
        }   

        if(a==b) return "Tie";
        else if(a>b) return "Alice";
        else return "Bob";
    }   
};