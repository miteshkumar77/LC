// https://leetcode.com/problems/construct-quad-tree

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    
    Node* buildTree(int x0, int y0, int x1, int y1, vector<vector<int>>& grid) {
        if (x0 > x1 || y0 > y1) {
            return nullptr;
        }
        
        if (x0 == x1 && y0 == y1) {
            return new Node(grid[x0][y0], true); 
        }
        int xm = x0 + (x1 - x0)/2;
        int ym = y0 + (y1 - y0)/2;
        
        
        Node* tl = buildTree(x0, y0, xm, ym, grid);
        Node* tr = buildTree(xm + 1, y0, x1, ym, grid); 
        Node* bl = buildTree(x0, ym + 1, xm, y1, grid); 
        Node* br = buildTree(xm + 1, ym + 1, x1, y1, grid); 
        
        if (!(tl || tr || bl || br)) {
            return new Node(grid[x0][y0], true);
        } else if (
            (tl && tr && bl && br) &&
            (tl -> isLeaf && tr -> isLeaf && bl -> isLeaf && br -> isLeaf) &&
            (tl -> val == tr -> val && tr -> val == bl -> val && bl -> val == br -> val)
        ) {
            return new Node(tl -> val, true);
        } else {
            return new Node(0, false, tl, tr, bl, br); 
        }
    }
    Node* construct(vector<vector<int>>& grid) {
        return buildTree(0, 0, grid[0].size() - 1, grid.size() - 1, grid); 
    }
};