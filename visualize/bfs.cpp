#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 3, inf = 1e9;
vector<int> adj[N];
int dis[N];
bool vis[N];
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<int> gen(1, 1000);
const int rnd = gen(rng);
void element_print(int i, int d) {
    cout << i;
    if (!vis[i]) {
        vis[i] = 1;

        cout << (dis[i] == d ? "[fill=green!30, " : "[fill=blue!30, ");

        cout << "as=";
        if(dis[i] > d) cout << "\\scriptsize{$" << i << ", \\infty$}]";
        else cout <<  "\\scriptsize{$" << i << ", " << dis[i] << "$}]";
    }
}

void print(int n, int d) {
    fill(vis, vis + n + 1, 0);
    cout << "\\begin{tikzpicture}\n";
    cout << "\\graph [nodes={circle, draw}, node distance = 20mm, spring layout, random seed=" << rnd <<"]{\n";
    for (int i = 1; i <= n; i++) {
        cout << "    ";
        element_print(i, d);
        bool done = false;
        for (int v : adj[i])
            if (v > i) {
                if (!done) {
                    done = 1;
                    cout << " -- { ";
                } else
                    cout << ", ";
                element_print(v, d);
            }
        if (done) cout << " }";
        cout << ";\n";
    }
    cout << "};\n\\end{tikzpicture}\n\n";
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    cout << "\\usetikzlibrary{graphs, graphdrawing, "
            "graphs.standard}\n\\usegdlibrary {force}\n\n";
    fill(dis, dis + n + 1, inf);

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    int mx = 0;
    while (!q.empty()) {
        int u = q.front();
        mx = max(mx, dis[u]);
        q.pop();
        for (int v : adj[u]) {
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 0; i <= mx; i++) print(n, i);
}
