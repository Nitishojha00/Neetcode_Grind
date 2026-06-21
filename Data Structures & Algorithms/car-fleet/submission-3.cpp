class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
         int n = position.size();
        vector<pair<int, double>> cars;

        // Store position and time to reach target
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort by starting position (descending)
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double lastTime = 0.0;

        for (auto& [pos, t] : cars) {
            if (t > lastTime) {
                // This car cannot catch up -> new fleet
                fleets++;
                lastTime = t;
            }
            // else it merges with the fleet ahead
        }

        return fleets;
    }
};
