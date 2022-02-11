class UnionFind {
public:
    UnionFind(int N) {
        for (int i = 0; i < N; ++i) {
            parent.push_back(i);
        }
        count = 0;
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }

    int getCount() {
        return count;
    }

    void addCount() {
        count++;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return;
        }
        
        parent[rootX] = rootY;
        count--;
    }

    int getCount() const {
        return count;
    }

private:
    vector<int> parent;
    int count;
};

class Solution {
private:
    bool inArea(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

public:
    vector<int> numIslands2(int m, int n, vector<vector<int>> &positions) {
        UnionFind unionFind(m * n);
        vector<bool> visited;
        for (size_t i = 0; i < m * n; i++) {
            visited.push_back(false);
        }

        int DIRECTIONS[4][2] = {{0,  1},
                                {1,  0},
                                {0,  -1},
                                {-1, 0}};
        vector<int> res;
        for (auto &position : positions) {
            int currX = position[0];
            int currY = position[1];

            int index = currX * n + currY;
            if (!visited[index]) {
                // 把水变成陆地，连通分量个数加 1
                unionFind.addCount();
                visited[index] = true;
                for (auto &direction : DIRECTIONS) {
                    int newX = currX + direction[0];
                    int newY = currY + direction[1];
                    int newIndex = newX * n + newY;
                    // 下面这三个条件很重要
                    if (inArea(newX, newY, m, n)
                        && visited[newIndex]
                        && !unionFind.isConnected(index, newIndex)) {
                        unionFind.unionSet(index, newIndex);
                    }
                }
            }
            res.push_back(unionFind.getCount());
        }
        return res;
    }
};

