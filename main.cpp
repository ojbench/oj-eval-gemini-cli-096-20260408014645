#include <iostream>
#include <vector>

using namespace std;

int depth[10005];
int parent[10005];

void build_tree(int p, int d) {
    int val;
    if (!(cin >> val)) return;
    if (val == -1) return;
    
    depth[val] = d;
    parent[val] = p;
    
    build_tree(val, d + 1);
    build_tree(val, d + 1);
}

int main() {
    for (int i = 0; i < 10005; ++i) {
        depth[i] = -1;
        parent[i] = -1;
    }
    
    int q;
    if (!(cin >> q)) return 0;
    
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }
    
    build_tree(-1, 0);
    
    for (int i = 0; i < q; ++i) {
        int x = queries[i].first;
        int y = queries[i].second;
        if (depth[x] != -1 && depth[y] != -1 && depth[x] == depth[y] && parent[x] != parent[y]) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    
    return 0;
}
