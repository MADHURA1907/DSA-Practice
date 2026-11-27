class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minimumPrice = INT_MAX;

        for (auto& item : items) {
            minimumPrice = min(minimumPrice, item[1]);
        }

        vector<int> freeItems(n, 0);

        // Calculate the number of free items obtained
        // by purchasing each item type.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    freeItems[i]++;
                }
            }
        }

        // Group items by their prices.
        vector<vector<int>> groups(budget + 1);

        for (int i = 0; i < n; i++) {
            int price = items[i][1];

            if (price <= budget) {
                groups[price].push_back(1 + freeItems[i]);
            }
        }

        int maximumItems = 0;

        // Try every possible minimum price among purchased items.
        for (int minimum = 1; minimum <= budget; minimum++) {

            if (groups[minimum].empty()) {
                continue;
            }

            vector<int> dp(budget + 1, -1);

            // At least one item having this minimum price
            // must be purchased.
            int bestValue = *max_element(
                groups[minimum].begin(),
                groups[minimum].end()
            );

            dp[minimum] = bestValue;

            // Process all other item types with price >= minimum.
            for (int price = minimum + 1; price <= budget; price++) {
                for (int value : groups[price]) {
                    for (int cost = budget; cost >= price; cost--) {
                        if (dp[cost - price] != -1) {
                            dp[cost] = max(
                                dp[cost],
                                dp[cost - price] + value
                            );
                        }
                    }
                }
            }

            // Add extra copies of the cheapest activated item.
            for (int cost = minimum; cost <= budget; cost++) {
                if (dp[cost] != -1) {
                    int total = dp[cost] +
                                (budget - cost) / minimum;

                    maximumItems = max(maximumItems, total);
                }
            }
        }

        return maximumItems;
    }
};

