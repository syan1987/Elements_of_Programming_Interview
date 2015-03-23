#include <iostream>
#include <vector>
using namespace std;

bool DFS(vector<vector<int> > &maze, int x, int y, int size_x, int size_y) {
    if (x<0 || x>=size_x) return false;
    if (y<0 || y>=size_y) return false;
    if (maze[x][y] == -1) return false;
    if (maze[x][y] == 1) return true;

    maze[x][y] = -2;
    if (DFS(maze, x+1, y, size_x, size_y)) return true;
    if (DFS(maze, x-1, y, size_x, size_y)) return true;
    if (DFS(maze, x, y+1, size_x, size_y)) return true;
    if (DFS(maze, x, y-1, size_x, size_y)) return true;

    return false;
}

int main() {
    // 1 means Exit, 0 means space, -1 means wall, -2 means already visited
    vector<vector<int> > maze;
    DFS(maze, 0, 0, 10, 10);
    return 0;
}
