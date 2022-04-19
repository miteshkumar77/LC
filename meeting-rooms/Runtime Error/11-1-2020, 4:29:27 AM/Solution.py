// https://leetcode.com/problems/meeting-rooms

class Solution(object):
    def canAttendMeetings(self, intervals):
        intervals.sort(key=lambda x : x[1])
        e = intervals[0][1]
        for i in range(1, len(intervals)):
            if e > intervals[i][0]:
                return False
            e = intervals[i][1]
        return True
        