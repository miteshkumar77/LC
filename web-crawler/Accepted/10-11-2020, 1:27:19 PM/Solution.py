// https://leetcode.com/problems/web-crawler

# """
# This is HtmlParser's API interface.
# You should not implement it, or speculate about its implementation
# """
#class HtmlParser(object):
#    def getUrls(self, url):
#        """
#        :type url: str
#        :rtype List[str]
#        """

class Solution(object):
    def crawl(self, startUrl, htmlParser):
        """
        :type startUrl: str
        :type htmlParser: HtmlParser
        :rtype: List[str]
        """
        # https://example.org
        def hostName(s):
            tmp = s[7:]
            i = tmp.find('/')
            i = i if i != -1 else len(tmp)
            tmp = tmp[:i]
            return tmp
        
        
        visited = set()
        
        from collections import deque
        
        q = deque()
        host = hostName(startUrl)
        
        q.append(startUrl)
        
        while q:
            top = q.popleft()
            if top in visited or hostName(top) != host:
                continue
            visited.add(top)
            l = htmlParser.getUrls(top)
            for i in l:
                q.append(i)
        
        return [i for i in visited]
    
            
            
            
        
        
        
        
        
        
        