 int maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();
    vector<pair<int, int>> meetings;

    // Pairing start and end times of meetings
    for (int i = 0; i < n; i++) {
        meetings.push_back({end[i], start[i]});
    }

    // Sorting meetings by end time
    sort(meetings.begin(), meetings.end());

    vector<int> ans; // To store selected meeting indexes

    for (int i = 0; i < n; i++) {
        // If ans is empty or current meeting starts after the last selected meeting ends
        if (ans.empty() || meetings[i].second > meetings[ans.back()].first) {
            ans.push_back(i);
        } else {
            // If current meeting's end time is earlier, replace the last one
            if (meetings[i].first < meetings[ans.back()].first) {
                ans.pop_back();
                ans.push_back(i);
            }
        }
    }

    return ans.size();
}