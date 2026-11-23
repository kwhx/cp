## Part A

### A1. Big Sum

```cpp
long long a, b; cin >> a >> b;
cout << a + b;
```

### A2. Division Report

```cpp
int a, b; cin >> a >> b;
cout << a / b << ' ' << a % b << ' ' << fixed << setprecision(3) << (double)a / b;
```

### A3. Average

```cpp
int n; cin >> n;
long long s = 0;
for (int i = 0; i < n; ++i) { long long x; cin >> x; s += x; }
cout << fixed << setprecision(2) << (double)s / n;
```

### A4. Factorial

```cpp
int n; cin >> n;
long long f = 1;
for (int i = 2; i <= n; ++i) f *= i;
cout << f;
```

### A5. Wrapping Sum

```cpp
unsigned a, b; cin >> a >> b;
unsigned w = a + b;
long long t = (long long)a + b;
cout << w << ' ' << t;
```

### A6. Safe Product

```cpp
long long a, b; cin >> a >> b;
long long p = a * b;
cout << p << ' ' << (p > 2147483647LL ? "YES" : "NO");
```

### A7. Digit Sum

```cpp
long long n; cin >> n;
int s = 0;
while (n > 0) { s += n % 10; n /= 10; }
cout << s;
```

### A8. Powers of Two

```cpp
int k; cin >> k;
int c = 0;
for (int j = 0; j <= k; ++j) if ((1LL << j) > 2147483647LL) ++c;
cout << (1LL << k) << ' ' << c;
```

### A9. Collatz Peak

```cpp
long long x; cin >> x;
int steps = 0; long long mx = x;
while (x != 1) {
    x = (x % 2 == 0) ? x / 2 : 3 * x + 1;
    mx = max(mx, x); ++steps;
}
cout << steps << ' ' << mx;
```

### A10. Case Flip

```cpp
string s; getline(cin, s);
for (char &c : s) {
    if (isupper(c)) c = tolower(c);
    else if (islower(c)) c = toupper(c);
}
cout << s;
```

### A11. Character Classes

```cpp
string s; getline(cin, s);
int l = 0, d = 0, sp = 0, p = 0;
for (char c : s) {
    if (isalpha(c)) ++l;
    else if (isdigit(c)) ++d;
    else if (isspace(c)) ++sp;
    else if (ispunct(c)) ++p;
}
cout << l << ' ' << d << ' ' << sp << ' ' << p;
```

### A12. Vowel Tally

```cpp
string s; cin >> s;
int c = 0;
for (char ch : s) {
    char l = tolower(ch);
    if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u') ++c;
}
cout << c;
```

### A13. Digits To Number

```cpp
string s; cin >> s;
long long v = 0;
for (char c : s) v = v * 10 + (c - '0');
cout << v * 2;
```

### A14. Caesar Shift

```cpp
long long k; string s; cin >> k >> s;
for (char &c : s) c = 'a' + (c - 'a' + k % 26) % 26;
cout << s;
```

### A15. Hex To Decimal

```cpp
string s; cin >> s;
long long v = 0;
for (char c : s) {
    int d = isdigit(c) ? c - '0' : c - 'A' + 10;
    v = v * 16 + d;
}
cout << v;
```

### A16. Equal Frequencies

```cpp
string s; cin >> s;
int cnt[26] = {};
for (char c : s) ++cnt[c - 'a'];
int f = 0; bool ok = true;
for (int i = 0; i < 26; ++i)
    if (cnt[i]) { if (!f) f = cnt[i]; else if (cnt[i] != f) ok = false; }
cout << (ok ? "YES" : "NO");
```

### A17. Letters-Only Palindrome

```cpp
string s; getline(cin, s);
string t;
for (char c : s) if (isalpha(c)) t += tolower(c);
bool ok = true;
for (size_t i = 0; i < t.size() / 2; ++i)
    if (t[i] != t[t.size() - 1 - i]) ok = false;
cout << (ok ? "YES" : "NO");
```

### A18. Run-Length Encoding

```cpp
string s; cin >> s;
size_t i = 0;
while (i < s.size()) {
    size_t j = i;
    while (j < s.size() && s[j] == s[i]) ++j;
    cout << s[i] << (j - i);
    i = j;
}
```

### A19. Reverse Each Word

```cpp
int n; cin >> n;
for (int k = 0; k < n; ++k) {
    string w, r; cin >> w;
    for (int i = (int)w.size() - 1; i >= 0; --i) r += w[i];
    cout << r << (k + 1 < n ? " " : "");
}
```

### A20. Join And Measure

```cpp
string s, t; cin >> s >> t;
string r = s + t;
cout << r << ' ' << r.size();
```

### A21. Starts With

```cpp
string s, t; cin >> s >> t;
bool ok = t.size() <= s.size();
for (size_t i = 0; ok && i < t.size(); ++i)
    if (s[i] != t[i]) ok = false;
cout << (ok ? "YES" : "NO");
```

### A22. Overlapping Occurrences

```cpp
string s, t; cin >> s >> t;
int c = 0;
for (size_t i = 0; i + t.size() <= s.size(); ++i) {
    bool ok = true;
    for (size_t j = 0; j < t.size(); ++j)
        if (s[i + j] != t[j]) { ok = false; break; }
    if (ok) ++c;
}
cout << c;
```

### A23. Strip Vowels

```cpp
string s; getline(cin, s);
string r;
for (char c : s) {
    char l = tolower(c);
    if (!(l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u')) r += c;
}
cout << r;
```

### A24. Smallest Word

```cpp
string a, b, c; cin >> a >> b >> c;
cout << min(a, min(b, c));
```

### A25. Anagram Check

```cpp
string s, t; cin >> s >> t;
int cnt[26] = {};
for (char c : s) ++cnt[c - 'a'];
for (char c : t) --cnt[c - 'a'];
bool ok = true;
for (int i = 0; i < 26; ++i) if (cnt[i] != 0) ok = false;
cout << (ok ? "YES" : "NO");
```

### A26. Common Prefix

```cpp
int n; cin >> n;
string p; cin >> p;
for (int i = 1; i < n; ++i) {
    string w; cin >> w;
    size_t k = 0;
    while (k < p.size() && k < w.size() && p[k] == w[k]) ++k;
    p.resize(k);
}
cout << (p.empty() ? "(none)" : p);
```

### A27. Collapse Spaces

```cpp
string s; getline(cin, s);
string out; bool pending = false;
for (char c : s) {
    if (c == ' ') { if (!out.empty()) pending = true; }
    else { if (pending) out += ' '; pending = false; out += c; }
}
cout << out;
```

### A28. Sum Max Min

```cpp
int n; cin >> n;
long long s = 0; int mx = INT_MIN, mn = INT_MAX;
for (int i = 0; i < n; ++i) { int x; cin >> x; s += x; mx = max(mx, x); mn = min(mn, x); }
cout << s << ' ' << mx << ' ' << mn;
```

### A29. Print Reversed

```cpp
int n; cin >> n;
vector<int> v(n);
for (int &x : v) cin >> x;
for (int i = n - 1; i >= 0; --i) cout << v[i] << (i ? " " : "");
```

### A30. Above Average

```cpp
int n; cin >> n;
vector<long long> v(n);
long long s = 0;
for (auto &x : v) { cin >> x; s += x; }
int c = 0;
for (long long x : v) if (x * n > s) ++c;
cout << c;
```

### A31. Prefix Sums

```cpp
int n; cin >> n;
long long s = 0;
for (int i = 0; i < n; ++i) { long long x; cin >> x; s += x; cout << s << (i + 1 < n ? " " : ""); }
```

### A32. Second Largest

```cpp
int n; cin >> n;
vector<int> v(n);
for (int &x : v) cin >> x;
int mx = v[0];
for (int x : v) mx = max(mx, x);
bool has = false; int sec = 0;
for (int x : v) if (x < mx && (!has || x > sec)) { sec = x; has = true; }
if (has) cout << sec; else cout << "NONE";
```

### A33. Rotate Right

```cpp
int n; long long k; cin >> n >> k;
vector<int> v(n), r(n);
for (int &x : v) cin >> x;
for (int i = 0; i < n; ++i) r[(i + k) % n] = v[i];
for (int i = 0; i < n; ++i) cout << r[i] << (i + 1 < n ? " " : "");
```

### A34. Distinct In Order

```cpp
int n; cin >> n;
vector<int> out;
for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    bool seen = false;
    for (int y : out) if (y == x) seen = true;
    if (!seen) out.push_back(x);
}
for (size_t i = 0; i < out.size(); ++i) cout << out[i] << (i + 1 < out.size() ? " " : "");
```

### A35. Longest Increasing Run

```cpp
int n; cin >> n;
vector<int> v(n);
for (int &x : v) cin >> x;
int best = 1, cur = 1;
for (int i = 1; i < n; ++i) { cur = v[i] > v[i - 1] ? cur + 1 : 1; best = max(best, cur); }
cout << best;
```

### A36. First Pair With Sum

```cpp
int n; long long T; cin >> n >> T;
vector<long long> a(n);
for (auto &x : a) cin >> x;
for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
        if (a[i] + a[j] == T) { cout << i + 1 << ' ' << j + 1; return 0; }
cout << -1;
```

### A37. Row And Column Sums

```cpp
int n, m; cin >> n >> m;
vector<vector<long long>> g(n, vector<long long>(m));
for (auto &r : g) for (auto &x : r) cin >> x;
for (int i = 0; i < n; ++i) { long long s = 0; for (int j = 0; j < m; ++j) s += g[i][j]; cout << s << (i + 1 < n ? " " : "\n"); }
for (int j = 0; j < m; ++j) { long long s = 0; for (int i = 0; i < n; ++i) s += g[i][j]; cout << s << (j + 1 < m ? " " : ""); }
```

### A38. Both Diagonals

```cpp
int n; cin >> n;
long long a = 0, b = 0;
for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
        long long x; cin >> x;
        if (i == j) a += x;
        if (i + j == n - 1) b += x;
    }
cout << a << ' ' << b;
```

### A39. Count Hashes

```cpp
char g[55][55];

int n, m; cin >> n >> m;
int c = 0;
for (int i = 0; i < n; ++i) {
    cin >> g[i];
    for (int j = 0; j < m; ++j) if (g[i][j] == '#') ++c;
}
cout << c;
```

### A40. Transpose

```cpp
int n, m; cin >> n >> m;
vector<vector<int>> g(n, vector<int>(m));
for (auto &r : g) for (int &x : r) cin >> x;
for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) cout << g[i][j] << (i + 1 < n ? " " : "");
    if (j + 1 < m) cout << '\n';
}
```

### A41. Mirror Image

```cpp
int n, m; cin >> n >> m;
for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    for (int j = m - 1; j >= 0; --j) cout << s[j];
    if (i + 1 < n) cout << '\n';
}
```

### A42. Minesweeper

```cpp
int n, m; cin >> n >> m;
vector<string> g(n);
for (auto &r : g) cin >> r;
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        if (g[i][j] == '*') { cout << '*'; continue; }
        int c = 0;
        for (int di = -1; di <= 1; ++di)
            for (int dj = -1; dj <= 1; ++dj) {
                int a = i + di, b = j + dj;
                if ((di || dj) && a >= 0 && a < n && b >= 0 && b < m && g[a][b] == '*') ++c;
            }
        cout << c;
    }
    if (i + 1 < n) cout << '\n';
}
```

### A43. Spiral Order

```cpp
int n, m; cin >> n >> m;
vector<vector<int>> g(n, vector<int>(m));
for (auto &r : g) for (int &x : r) cin >> x;
vector<int> out;
int t = 0, b = n - 1, l = 0, r = m - 1;
while (t <= b && l <= r) {
    for (int j = l; j <= r; ++j) out.push_back(g[t][j]);
    ++t;
    for (int i = t; i <= b; ++i) out.push_back(g[i][r]);
    --r;
    if (t <= b) { for (int j = r; j >= l; --j) out.push_back(g[b][j]); --b; }
    if (l <= r) { for (int i = b; i >= t; --i) out.push_back(g[i][l]); ++l; }
}
for (size_t i = 0; i < out.size(); ++i) cout << out[i] << (i + 1 < out.size() ? " " : "");
```

### A44. Saddle Points

```cpp
int n, m; cin >> n >> m;
vector<vector<int>> g(n, vector<int>(m));
for (auto &r : g) for (int &x : r) cin >> x;
vector<int> rmin(n, INT_MAX), cmax(m, INT_MIN);
for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) { rmin[i] = min(rmin[i], g[i][j]); cmax[j] = max(cmax[j], g[i][j]); }
int c = 0;
for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) if (g[i][j] == rmin[i] && g[i][j] == cmax[j]) ++c;
cout << c;
```

### A45. Rotate Picture

```cpp
int n, m; cin >> n >> m;
vector<string> g(n);
for (auto &r : g) cin >> r;
for (int j = 0; j < m; ++j) {
    for (int i = n - 1; i >= 0; --i) cout << g[i][j];
    if (j + 1 < m) cout << '\n';
}
```

### A46. Every Second

```cpp
int n; cin >> n;
vector<int> v(n);
for (int &x : v) cin >> x;
auto it = v.begin();
bool first = true;
while (true) {
    if (!first) cout << ' ';
    cout << *it; first = false;
    if (v.end() - it <= 2) break;
    it += 2;
}
```

### A47. Shout First Word

```cpp
string s; getline(cin, s);
for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it) *it = toupper(*it);
cout << s;
```

### A48. Iterator Sum

```cpp
int n; cin >> n;
vector<long long> v(n);
for (auto &x : v) cin >> x;
long long s = 0;
for (auto it = v.begin(); it != v.end(); ++it) s += *it;
cout << s;
```

### A49. Binary Search

```cpp
int n; cin >> n;
vector<int> v(n);
for (int &x : v) cin >> x;
int x; cin >> x;
auto beg = v.begin(), end = v.end();
int ans = -1;
while (beg < end) {
    auto mid = beg + (end - beg) / 2;
    if (*mid == x) { ans = mid - v.begin(); break; }
    if (*mid < x) beg = mid + 1; else end = mid;
}
cout << ans;
```

### A50. Reverse With Two Iterators

```cpp
int n; cin >> n;
vector<int> v(n);
for (int &x : v) cin >> x;
auto b = v.begin(), e = v.end();
while (b < e) { --e; if (b == e) break; swap(*b, *e); ++b; }
for (int i = 0; i < n; ++i) cout << v[i] << (i + 1 < n ? " " : "");
```

### A51. First Negative

```cpp
int n; cin >> n;
vector<int> v(n);
for (int &x : v) cin >> x;
int ans = -1;
for (auto it = v.begin(); it != v.end(); ++it)
    if (*it < 0) { ans = it - v.begin(); break; }
cout << ans;
```

### A52. Delete Evens

```cpp
int n; cin >> n;
vector<int> v(n);
for (int &x : v) cin >> x;
for (auto it = v.begin(); it != v.end(); ) {
    if (*it % 2 == 0) it = v.erase(it); else ++it;
}
if (v.empty()) cout << "EMPTY";
for (size_t i = 0; i < v.size(); ++i) cout << v[i] << (i + 1 < v.size() ? " " : "");
```

### A53. Lower Median

```cpp
int n; cin >> n;
vector<int> v(n);
for (int &x : v) cin >> x;
sort(v.begin(), v.end());
cout << *(v.begin() + (n - 1) / 2);
```

### A54. Merge Two Sorted

```cpp
int n, m; cin >> n >> m;
vector<int> a(n), b(m), c;
for (int &x : a) cin >> x;
for (int &x : b) cin >> x;
auto i = a.begin(), j = b.begin();
while (i != a.end() && j != b.end()) {
    if (*i <= *j) c.push_back(*i++); else c.push_back(*j++);
}
while (i != a.end()) c.push_back(*i++);
while (j != b.end()) c.push_back(*j++);
for (size_t k = 0; k < c.size(); ++k) cout << c[k] << (k + 1 < c.size() ? " " : "");
```

### A55. Bump The Larger

```cpp
int a, b; cin >> a >> b;
int &r = (a >= b) ? a : b;
r += 100;
cout << a << ' ' << b;
```

### A56. Pointer Walk

```cpp
int a[5];
for (int i = 0; i < 5; ++i) cin >> a[i];
long long s = 0;
for (int *p = a; p != a + 5; ++p) s += *p;
cout << s;
```

### A57. Double In Place

```cpp
int n; cin >> n;
vector<long long> v(n);
for (auto &x : v) cin >> x;
for (auto &x : v) x *= 2;
for (int i = 0; i < n; ++i) cout << v[i] << (i + 1 < n ? " " : "");
```

### A58. Bump The Maximum

```cpp
int n; cin >> n;
vector<int> v(n);
for (int &x : v) cin >> x;
int *p = &v[0];
for (int &x : v) if (x > *p) p = &x;
++*p;
for (int i = 0; i < n; ++i) cout << v[i] << (i + 1 < n ? " " : "\n");
cout << p - &v[0];
```

### A59. Total And Longest

```cpp
int n; cin >> n;
vector<string> v(n);
for (auto &w : v) cin >> w;
size_t total = 0; string best;
for (const auto &w : v) { total += w.size(); if (w.size() > best.size()) best = w; }
cout << total << ' ' << best;
```

### A60. Row Sums Via Pointer

```cpp
int a[2][3];
for (int i = 0; i < 2; ++i) for (int j = 0; j < 3; ++j) cin >> a[i][j];
int (*p)[3] = a;
for (int r = 0; r < 2; ++r) {
    int s = 0;
    for (int j = 0; j < 3; ++j) s += (*(p + r))[j];
    cout << s << (r ? "" : " ");
}
```

### A61. Pointer Palindrome

```cpp
char s[105];
cin >> s;
char *l = s, *r = s + strlen(s) - 1;
bool ok = true;
while (l < r) { if (*l != *r) ok = false; ++l; --r; }
cout << (ok ? "YES" : "NO");
```

### A62. Sum Of Squares

```cpp
int n; cin >> n;
long long s = 0;
for (int i = 0; i < n; ++i) { int x; cin >> x; s += 1LL * x * x; }
cout << s;
```

### A63. Add Row Maximum

```cpp
int n, m; cin >> n >> m;
vector<vector<long long>> g(n, vector<long long>(m));
for (auto &row : g) for (auto &c : row) cin >> c;
for (auto &row : g) {
    long long mx = row[0];
    for (long long c : row) mx = max(mx, c);
    for (auto &c : row) c += mx;
}
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << g[i][j] << (j + 1 < m ? " " : "");
    if (i + 1 < n) cout << '\n';
}
```

### A64. Squared Distance

```cpp
struct Point { long long x, y; };

Point a, b; cin >> a.x >> a.y >> b.x >> b.y;
long long dx = a.x - b.x, dy = a.y - b.y;
cout << dx * dx + dy * dy;
```

### A65. Top Scorer

```cpp
struct Student { string name; int score; };

int n; cin >> n;
vector<Student> v(n);
for (auto &s : v) cin >> s.name >> s.score;
int b = 0;
for (int i = 1; i < n; ++i) if (v[i].score > v[b].score) b = i;
cout << v[b].name << ' ' << v[b].score;
```

### A66. Total Area

```cpp
struct Rect { long long w, h; };

int n; cin >> n;
long long area = 0, per = 0;
for (int i = 0; i < n; ++i) { Rect r; cin >> r.w >> r.h; area += r.w * r.h; per += 2 * (r.w + r.h); }
cout << area << ' ' << per;
```

### A67. Heaviest Edge

```cpp
struct Edge { int u, v, w; };

int n, m; cin >> n >> m;
vector<Edge> e(m);
long long total = 0; int b = 0;
for (int i = 0; i < m; ++i) { cin >> e[i].u >> e[i].v >> e[i].w; total += e[i].w; if (e[i].w > e[b].w) b = i; }
cout << e[b].u << ' ' << e[b].v << ' ' << e[b].w << ' ' << total;
```

### A68. Positive Counter

```cpp
struct Counter { int hits = 0; long long total = 0; };

int n; cin >> n;
Counter c;
for (int i = 0; i < n; ++i) { long long x; cin >> x; if (x > 0) { ++c.hits; c.total += x; } }
cout << c.hits << ' ' << c.total;
```

### A69. Minutes Between

```cpp
struct Time { int h, m; };

Time a, b; cin >> a.h >> a.m >> b.h >> b.m;
cout << (b.h * 60 + b.m) - (a.h * 60 + a.m);
```

### A70. Farthest Pair

```cpp
struct Pt { long long x, y; };

int n; cin >> n;
vector<Pt> p(n);
for (auto &q : p) cin >> q.x >> q.y;
long long best = 0;
for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
        long long dx = p[i].x - p[j].x, dy = p[i].y - p[j].y;
        best = max(best, dx * dx + dy * dy);
    }
cout << best;
```

### A71. Rank The Students

```cpp
struct Student { string name; int score; };

int n; cin >> n;
vector<Student> v(n);
for (auto &s : v) cin >> s.name >> s.score;
for (int i = 0; i < n; ++i) {
    int b = i;
    for (int j = i + 1; j < n; ++j)
        if (v[j].score > v[b].score || (v[j].score == v[b].score && v[j].name < v[b].name)) b = j;
    swap(v[i], v[b]);
}
for (int i = 0; i < n; ++i) cout << v[i].name << ' ' << v[i].score << (i + 1 < n ? "\n" : "");
```

### A72. Deepest Overlap

```cpp
struct Seg { int l, r; };

int n; cin >> n;
int cnt[1005] = {};
for (int i = 0; i < n; ++i) {
    Seg s; cin >> s.l >> s.r;
    for (int x = s.l; x <= s.r; ++x) ++cnt[x];
}
int best = 0;
for (int x = 0; x <= 1000; ++x) best = max(best, cnt[x]);
cout << best;
```

## Part B

### B1. Parity of the Haul

```cpp
int t; cin >> t;
while (t--) {
    int n; cin >> n;
    long long s = 0;
    for (int i = 0; i < n; ++i) { long long x; cin >> x; s += x; }
    cout << (s % 2 == 0 ? "EVEN" : "ODD") << '\n';
}
```

### B2. Minutes To Walk Home

```cpp
long long a, b, k; cin >> a >> b >> k;
long long d = a > b ? a - b : b - a;
cout << (d + k - 1) / k;
```

### B3. Longest Words

```cpp
int n; cin >> n;
size_t best = 0; int cnt = 0;
for (int i = 0; i < n; ++i) {
    string w; cin >> w;
    if (w.size() > best) { best = w.size(); cnt = 1; }
    else if (w.size() == best) ++cnt;
}
cout << best << ' ' << cnt;
```

### B4. Sharing Candies

```cpp
long long n, k; cin >> n >> k;
cout << n / k << ' ' << n % k;
```

### B5. Until Midnight

```cpp
int h, m; cin >> h >> m;
cout << 1440 - (h * 60 + m);
```

### B6. Favourite Digit

```cpp
long long n; int d; cin >> n >> d;
int c = 0;
while (n > 0) { if (n % 10 == d) ++c; n /= 10; }
cout << c;
```

### B7. Even Seats

```cpp
int n; cin >> n;
long long s = 0;
for (int i = 1; i <= n; ++i) { long long x; cin >> x; if (i % 2 == 0) s += x; }
cout << s;
```

### B8. Shouting Rule

```cpp
string s; cin >> s;
int up = 0;
for (char c : s) if (isupper(c)) ++up;
bool upper = up * 2 > (int)s.size();
for (char &c : s) c = upper ? toupper(c) : tolower(c);
cout << s;
```

### B9. Shopping Cart

```cpp
int n; long long B; cin >> n >> B;
long long total = 0;
for (int i = 0; i < n; ++i) { long long p, q; cin >> p >> q; total += p * q; }
if (total <= B) cout << "OK " << B - total;
else cout << "SHORT " << total - B;
```

### B10. Missing Positive

```cpp
int n; cin >> n;
vector<bool> seen(n + 2, false);
for (int i = 0; i < n; ++i) { int x; cin >> x; if (x >= 1 && x <= n + 1) seen[x] = true; }
int ans = 1;
while (seen[ans]) ++ans;
cout << ans;
```

### B11. Staircase

```cpp
int n; cin >> n;
for (int i = 1; i <= n; ++i) {
    cout << string(n - i, ' ') << string(i, '#');
    if (i < n) cout << '\n';
}
```

### B12. Leap Years

```cpp
int a, b; cin >> a >> b;
int c = 0;
for (int y = a; y <= b; ++y)
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) ++c;
cout << c;
```

### B13. Warm Streak

```cpp
int n, T; cin >> n >> T;
int best = 0, cur = 0;
for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    cur = (x >= T) ? cur + 1 : 0;
    best = max(best, cur);
}
cout << best;
```

### B14. Balanced Or Not

```cpp
string s; cin >> s;
int bal = 0; bool ok = true;
for (char c : s) {
    bal += (c == '(') ? 1 : -1;
    if (bal < 0) ok = false;
}
cout << ((ok && bal == 0) ? "YES" : "NO");
```

### B15. Two Dice

```cpp
int s; cin >> s;
int c = 0;
for (int a = 1; a <= 6; ++a)
    for (int b = 1; b <= 6; ++b) if (a + b == s) ++c;
cout << c;
```

### B16. Chessboard

```cpp
int n, m; cin >> n >> m;
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << ((i + j) % 2 == 0 ? 'B' : 'W');
    if (i + 1 < n) cout << '\n';
}
```

### B17. Password Check

```cpp
string s; cin >> s;
bool lo = false, up = false, dg = false;
for (char c : s) { if (islower(c)) lo = true; if (isupper(c)) up = true; if (isdigit(c)) dg = true; }
cout << ((s.size() >= 8 && lo && up && dg) ? "OK" : "WEAK");
```

### B18. Biggest Jump

```cpp
int n; cin >> n;
vector<long long> h(n);
for (auto &x : h) cin >> x;
long long best = 0;
for (int i = 1; i < n; ++i) best = max(best, llabs(h[i] - h[i - 1]));
cout << best;
```

### B19. Twin Cards

```cpp
int n; cin >> n;
vector<int> a(n);
for (int &x : a) cin >> x;
int c = 0;
for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) if (a[i] == a[j]) ++c;
cout << c;
```

### B20. Timer Display

```cpp
long long s; cin >> s;
cout << s / 86400 << ' ' << s % 86400 / 3600 << ' ' << s % 3600 / 60 << ' ' << s % 60;
```

### B21. Full Rows

```cpp
int n, m; cin >> n >> m;
int c = 0;
for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    bool full = true;
    for (char ch : s) if (ch != '#') full = false;
    if (full) ++c;
}
cout << c;
```

### B22. Overdraft

```cpp
long long S; int n; cin >> S >> n;
int ans = 0;
for (int i = 1; i <= n; ++i) {
    long long x; cin >> x; S += x;
    if (S < 0 && ans == 0) ans = i;
}
cout << ans;
```

### B23. Look And Say

```cpp
string s; cin >> s;
size_t i = 0;
while (i < s.size()) {
    size_t j = i;
    while (j < s.size() && s[j] == s[i]) ++j;
    cout << (j - i) << s[i];
    i = j;
}
```

### B24. Stack Eraser

```cpp
string s; cin >> s;
string st;
for (char c : s) {
    if (!st.empty() && st.back() == c) st.pop_back();
    else st.push_back(c);
}
cout << (st.empty() ? "EMPTY" : st);
```

### B25. Border Sum

```cpp
int n, m; cin >> n >> m;
long long s = 0;
for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
        long long x; cin >> x;
        if (i == 0 || j == 0 || i == n - 1 || j == m - 1) s += x;
    }
cout << s;
```

### B26. Count The Peaks

```cpp
int n; cin >> n;
vector<int> a(n);
for (int &x : a) cin >> x;
int c = 0;
for (int i = 1; i + 1 < n; ++i) if (a[i] > a[i - 1] && a[i] > a[i + 1]) ++c;
cout << c;
```

### B27. Target Segments

```cpp
int n; long long K; cin >> n >> K;
vector<long long> a(n);
for (auto &x : a) cin >> x;
int c = 0;
for (int i = 0; i < n; ++i) {
    long long s = 0;
    for (int j = i; j < n; ++j) { s += a[j]; if (s == K) ++c; }
}
cout << c;
```

### B28. Lucky Numbers

```cpp
int n; cin >> n;
int c = 0;
for (int i = 1; i <= n; ++i) {
    int x = i; bool ok = true;
    while (x > 0) { int d = x % 10; if (d != 4 && d != 7) ok = false; x /= 10; }
    if (ok) ++c;
}
cout << c;
```

### B29. Common Letter

```cpp
string s; cin >> s;
int cnt[26] = {};
for (char c : s) ++cnt[c - 'a'];
int b = 0;
for (int i = 1; i < 26; ++i) if (cnt[i] > cnt[b]) b = i;
cout << char('a' + b) << ' ' << cnt[b];
```

### B30. To Binary

```cpp
long long n; cin >> n;
string b; int ones = 0;
while (n > 0) { b += char('0' + n % 2); ones += n % 2; n /= 2; }
for (int i = (int)b.size() - 1; i >= 0; --i) cout << b[i];
cout << ' ' << ones;
```

### B31. Rotated Copy

```cpp
string s, t; cin >> s >> t;
bool ok = false;
if (s.size() == t.size()) {
    int n = s.size();
    for (int k = 0; k < n; ++k) {
        bool m = true;
        for (int i = 0; i < n; ++i) if (s[(i + k) % n] != t[i]) { m = false; break; }
        if (m) ok = true;
    }
}
cout << (ok ? "YES" : "NO");
```

### B32. Cinema Booking

```cpp
int n, m, k; cin >> n >> m >> k;
int c = 0;
for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    for (int j = 0; j + k <= m; ++j) {
        bool ok = true;
        for (int t = 0; t < k; ++t) if (s[j + t] != '.') ok = false;
        if (ok) ++c;
    }
}
cout << c;
```

### B33. Digit Persistence

```cpp
long long n; cin >> n;
int steps = 0;
while (n >= 10) {
    long long p = 1;
    while (n > 0) { p *= n % 10; n /= 10; }
    n = p; ++steps;
}
cout << steps;
```

### B34. Zigzag

```cpp
int n; cin >> n;
vector<long long> a(n);
for (auto &x : a) cin >> x;
bool ok = true;
for (int i = 1; i < n; ++i) if (a[i] == a[i - 1]) ok = false;
for (int i = 1; ok && i + 1 < n; ++i)
    if ((a[i] > a[i - 1]) == (a[i + 1] > a[i])) ok = false;
cout << (ok ? "YES" : "NO");
```

### B35. Treasure Cell

```cpp
int n, m; cin >> n >> m;
vector<vector<long long>> g(n, vector<long long>(m));
for (auto &r : g) for (auto &x : r) cin >> x;
long long best = LLONG_MIN; int br = 0, bc = 0;
for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
        long long s = g[i][j];
        if (i > 0) s += g[i - 1][j];
        if (i + 1 < n) s += g[i + 1][j];
        if (j > 0) s += g[i][j - 1];
        if (j + 1 < m) s += g[i][j + 1];
        if (s > best) { best = s; br = i + 1; bc = j + 1; }
    }
cout << best << ' ' << br << ' ' << bc;
```

### B36. Fewest Coins

```cpp
long long x; cin >> x;
long long c = 0;
for (long long v : {100LL, 20LL, 10LL, 5LL, 1LL}) { c += x / v; x %= v; }
cout << c;
```

### B37. Balance Point

```cpp
int n; cin >> n;
vector<long long> a(n);
long long total = 0;
for (auto &x : a) { cin >> x; total += x; }
long long pre = 0; int ans = -1;
for (int k = 1; k < n; ++k) {
    pre += a[k - 1];
    if (pre * 2 == total) { ans = k; break; }
}
cout << ans;
```

### B38. Disorder

```cpp
int n; cin >> n;
vector<int> a(n);
for (int &x : a) cin >> x;
long long c = 0;
for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) if (a[i] > a[j]) ++c;
cout << c;
```

### B39. Weekdays Of A Month

```cpp
int s, d; cin >> s >> d;
int cnt[7] = {};
for (int i = 0; i < d; ++i) ++cnt[(s - 1 + i) % 7];
for (int i = 0; i < 7; ++i) cout << cnt[i] << (i < 6 ? " " : "");
```

### B40. Bubble Count

```cpp
int n; cin >> n;
vector<int> a(n);
for (int &x : a) cin >> x;
long long sw = 0;
for (int i = 0; i < n; ++i)
    for (int j = 0; j + 1 < n - i; ++j)
        if (a[j] > a[j + 1]) { swap(a[j], a[j + 1]); ++sw; }
cout << sw;
```

### B41. Nesting Depth

```cpp
string s; cin >> s;
int d = 0, best = 0;
for (char c : s) { d += (c == '(') ? 1 : -1; best = max(best, d); }
cout << best;
```

### B42. Pascal Rows

```cpp
int n; cin >> n;
vector<long long> row{1};
for (int r = 0; r < n; ++r) {
    for (size_t i = 0; i < row.size(); ++i) cout << row[i] << (i + 1 < row.size() ? " " : "");
    if (r + 1 < n) cout << '\n';
    vector<long long> nx(row.size() + 1, 1);
    for (size_t i = 1; i < row.size(); ++i) nx[i] = row[i - 1] + row[i];
    row = nx;
}
```

### B43. One Generation

```cpp
int n, m; cin >> n >> m;
vector<string> g(n), r(n);
for (auto &s : g) cin >> s;
r = g;
for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
        int c = 0;
        for (int di = -1; di <= 1; ++di)
            for (int dj = -1; dj <= 1; ++dj) {
                int a = i + di, b = j + dj;
                if ((di || dj) && a >= 0 && a < n && b >= 0 && b < m && g[a][b] == '#') ++c;
            }
        r[i][j] = (g[i][j] == '#') ? ((c == 2 || c == 3) ? '#' : '.') : (c == 3 ? '#' : '.');
    }
for (int i = 0; i < n; ++i) cout << r[i] << (i + 1 < n ? "\n" : "");
```

### B44. Sudoku Check

```cpp
vector<string> g(9);
for (auto &s : g) cin >> s;
bool ok = true;
for (int k = 0; k < 9; ++k) {
    int row[10] = {}, col[10] = {}, box[10] = {};
    for (int t = 0; t < 9; ++t) {
        ++row[g[k][t] - '0'];
        ++col[g[t][k] - '0'];
        ++box[g[k / 3 * 3 + t / 3][k % 3 * 3 + t % 3] - '0'];
    }
    for (int d = 1; d <= 9; ++d) if (row[d] != 1 || col[d] != 1 || box[d] != 1) ok = false;
}
cout << (ok ? "YES" : "NO");
```

### B45. Spiral Fill

```cpp
int n; cin >> n;
vector<vector<int>> g(n, vector<int>(n, 0));
int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};
int i = 0, j = 0, d = 0;
for (int v = 1; v <= n * n; ++v) {
    g[i][j] = v;
    int ni = i + di[d], nj = j + dj[d];
    if (ni < 0 || ni >= n || nj < 0 || nj >= n || g[ni][nj]) { d = (d + 1) % 4; ni = i + di[d]; nj = j + dj[d]; }
    i = ni; j = nj;
}
for (int a = 0; a < n; ++a) {
    for (int b = 0; b < n; ++b) cout << g[a][b] << (b + 1 < n ? " " : "");
    if (a + 1 < n) cout << '\n';
}
```

### B46. Smallest With Digit Sum

```cpp
int L, S; cin >> L >> S;
if (S > 9 * L) { cout << -1; return 0; }
if (L == 1) { cout << S; return 0; }
if (S < 1) { cout << -1; return 0; }
vector<int> d(L, 0);
int rem = S - 1;
for (int i = L - 1; i >= 1; --i) { d[i] = min(9, rem); rem -= d[i]; }
d[0] = 1 + rem;
for (int x : d) cout << x;
```

### B47. Huge Sum

```cpp
string a, b; cin >> a >> b;
string r; int carry = 0;
int i = (int)a.size() - 1, j = (int)b.size() - 1;
while (i >= 0 || j >= 0 || carry) {
    int s = carry;
    if (i >= 0) s += a[i--] - '0';
    if (j >= 0) s += b[j--] - '0';
    r += char('0' + s % 10);
    carry = s / 10;
}
for (int k = (int)r.size() - 1; k >= 0; --k) cout << r[k];
```

### B48. Big Factorial

```cpp
int n; cin >> n;
vector<int> d{1};
for (int f = 2; f <= n; ++f) {
    int carry = 0;
    for (size_t i = 0; i < d.size(); ++i) {
        int v = d[i] * f + carry;
        d[i] = v % 10; carry = v / 10;
    }
    while (carry) { d.push_back(carry % 10); carry /= 10; }
}
for (int i = (int)d.size() - 1; i >= 0; --i) cout << d[i];
```

### B49. Roman Numerals

```cpp
int n; cin >> n;
int val[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
string sym[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
for (int i = 0; i < 13; ++i)
    while (n >= val[i]) { cout << sym[i]; n -= val[i]; }
```

### B50. Roman To Number

```cpp
string s; cin >> s;
auto v = [](char c) { switch (c) { case 'I': return 1; case 'V': return 5; case 'X': return 10; case 'L': return 50; case 'C': return 100; case 'D': return 500; default: return 1000; } };
int total = 0;
for (size_t i = 0; i < s.size(); ++i) {
    int cur = v(s[i]);
    if (i + 1 < s.size() && cur < v(s[i + 1])) total -= cur; else total += cur;
}
cout << total;
```

### B51. Longest Palindrome Inside

```cpp
string s; cin >> s;
int n = s.size(), best = 1;
for (int c = 0; c < n; ++c) {
    for (int odd = 0; odd < 2; ++odd) {
        int l = c, r = c + odd;
        while (l >= 0 && r < n && s[l] == s[r]) { best = max(best, r - l + 1); --l; ++r; }
    }
}
cout << best;
```

### B52. Three Kinds Of Brackets

```cpp
string s; cin >> s;
vector<char> st; bool ok = true;
for (char c : s) {
    if (c == '(' || c == '[' || c == '{') st.push_back(c);
    else {
        if (st.empty()) { ok = false; break; }
        char o = st.back(); st.pop_back();
        if ((c == ')' && o != '(') || (c == ']' && o != '[') || (c == '}' && o != '{')) { ok = false; break; }
    }
}
cout << ((ok && st.empty()) ? "YES" : "NO");
```

### B53. Days Between

```cpp
int y1, m1, d1, y2, m2, d2; cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
auto leap = [](int y) { return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0); };
auto dim = [&](int y, int m) { int t[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; return m == 2 && leap(y) ? 29 : t[m - 1]; };
long long days = 0;
while (y1 != y2 || m1 != m2 || d1 != d2) {
    ++d1;
    if (d1 > dim(y1, m1)) { d1 = 1; ++m1; if (m1 > 12) { m1 = 1; ++y1; } }
    ++days;
}
cout << days;
```

### B54. Queen Attacks

```cpp
bool ob[1005][1005];

int n, k, r, c; cin >> n >> k >> r >> c;
for (int i = 0; i < k; ++i) { int a, b; cin >> a >> b; ob[a][b] = true; }
int total = 0;
for (int di = -1; di <= 1; ++di)
    for (int dj = -1; dj <= 1; ++dj) {
        if (!di && !dj) continue;
        int a = r + di, b = c + dj;
        while (a >= 1 && a <= n && b >= 1 && b <= n && !ob[a][b]) { ++total; a += di; b += dj; }
    }
cout << total;
```

### B55. Best Square

```cpp
int n, k; cin >> n >> k;
vector<vector<long long>> g(n, vector<long long>(n));
for (auto &r : g) for (auto &x : r) cin >> x;
long long best = LLONG_MIN;
for (int i = 0; i + k <= n; ++i)
    for (int j = 0; j + k <= n; ++j) {
        long long s = 0;
        for (int a = 0; a < k; ++a) for (int b = 0; b < k; ++b) s += g[i + a][j + b];
        best = max(best, s);
    }
cout << best;
```

### B56. Bulls And Cows

```cpp
string s, g; cin >> s >> g;
int bulls = 0, cs[10] = {}, cg[10] = {};
for (int i = 0; i < 4; ++i) {
    if (s[i] == g[i]) ++bulls;
    else { ++cs[s[i] - '0']; ++cg[g[i] - '0']; }
}
int cows = 0;
for (int d = 0; d < 10; ++d) cows += min(cs[d], cg[d]);
cout << bulls << ' ' << cows;
```

### B57. Busiest Moment

```cpp
int n; cin >> n;
vector<int> A(n), D(n);
for (int i = 0; i < n; ++i) cin >> A[i] >> D[i];
sort(A.begin(), A.end());
sort(D.begin(), D.end());
int j = 0, best = 0;
for (int i = 0; i < n; ++i) {
    while (D[j] <= A[i]) ++j;
    best = max(best, i + 1 - j);
}
cout << best;
```

### B58. Closest Pair

```cpp
int n; cin >> n;
vector<long long> a(n);
for (auto &x : a) cin >> x;
sort(a.begin(), a.end());
long long best = LLONG_MAX;
for (int i = 1; i < n; ++i) best = min(best, a[i] - a[i - 1]);
cout << best;
```

### B59. Counting Out

```cpp
int n, k; cin >> n >> k;
vector<int> p(n);
for (int i = 0; i < n; ++i) p[i] = i + 1;
int idx = 0;
while (p.size() > 1) {
    idx = (idx + k - 1) % p.size();
    p.erase(p.begin() + idx);
    if (idx == (int)p.size()) idx = 0;
}
cout << p[0];
```

### B60. Next Arrangement

```cpp
string s; cin >> s;
int n = s.size(), i = n - 2;
while (i >= 0 && s[i] >= s[i + 1]) --i;
if (i < 0) { cout << "NONE"; return 0; }
int j = n - 1;
while (s[j] <= s[i]) --j;
swap(s[i], s[j]);
int l = i + 1, r = n - 1;
while (l < r) swap(s[l++], s[r--]);
cout << s;
```