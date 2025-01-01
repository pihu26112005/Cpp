 int findPlatform(vector<int>& start, vector<int>& end) {
    int n = start.size();
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Pairing end times with start times for each train
    vector<pair<int, int>> meetings;
    for (int i = 0; i < n; i++) {
        meetings.push_back({end[i], start[i]});
    }

    // Sort meetings by their end time
    sort(meetings.begin(), meetings.end());

    int currentCount = 1; // Tracks the number of overlapping intervals
    int maxCount = 1;     // Tracks the maximum size of overlapping intervals

    // Loop through the sorted intervals
    for (int i = 1; i < n; i++) {
        if (meetings[i].second <= meetings[i - 1].first) {
            // The current interval overlaps with the last one
            currentCount++;
        } else {
            // No overlap, reset the current count
            currentCount = 1;
        }

        // Update the maximum count
        maxCount = max(maxCount, currentCount);

        // Merge intervals if needed
        meetings[i].first = max(meetings[i - 1].first, meetings[i].first);
    }

    return maxCount;
}