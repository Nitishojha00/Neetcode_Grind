class Solution {
public:
    bool solve(vector<int>& matchsticks, vector<int>& side, int index, int target)
    {
        if(index == matchsticks.size())
            return true;

        for(int i = 0; i < 4; i++)
        {
            // Cannot place this matchstick on this side
            if(side[i] + matchsticks[index] > target)
                continue;

            // Skip symmetric states
            if(i > 0 && side[i] == side[i - 1])
                continue;

            side[i] += matchsticks[index];

            if(solve(matchsticks, side, index + 1, target))
                return true;

            side[i] -= matchsticks[index];
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        if(sum % 4 != 0)
            return false;

        int target = sum / 4;

        // Largest sticks first for better pruning
        sort(matchsticks.rbegin(), matchsticks.rend());

        // If the largest stick itself is bigger than one side
        if(matchsticks[0] > target)
            return false;

        vector<int> side(4, 0);

        return solve(matchsticks, side, 0, target);
    }
};