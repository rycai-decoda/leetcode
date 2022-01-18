class Solution {
public:
    struct Meeting {
        int time;
        bool start;
    };
    int minMeetingRooms(vector<vector<int>>& intervals) {
        std::vector<Meeting> meetings;
        for (const auto& i : intervals) {
            Meeting m;
            m.time = i[0];
            m.start = true;
            meetings.push_back(m);
            
            m.time = i[1];
            m.start = false;
            meetings.push_back(m);
        }
        std::sort(meetings.begin(), meetings.end(), 
                  [](const Meeting& m1, const Meeting& m2) {
            // meeting ends first.
            if (m1.time == m2.time) {
                return !m1.start;
            }
                      
            return m1.time < m2.time;
        });
        
        
        int overlapped = 0;
        int rooms = 0;
        for (const Meeting& m : meetings) {
            if (m.start) {
                overlapped++;
            } else {
                overlapped--;
            }
            rooms = std::max(rooms, overlapped);
        }
        return rooms;
    }
};