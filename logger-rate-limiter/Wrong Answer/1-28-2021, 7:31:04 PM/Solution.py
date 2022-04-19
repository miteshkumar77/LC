// https://leetcode.com/problems/logger-rate-limiter

from collections import defaultdict
class Logger(object):
    
    log = defaultdict(lambda : 0)
    def __init__(self):
        
        pass
        

    def shouldPrintMessage(self, timestamp, message):
        if timestamp >= self.log[message]:
            self.log[message] = timestamp + 10
            return True
        return False
        


# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)