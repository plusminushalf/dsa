#include <iostream>
using namespace std;

int getMax(int tl, int t, int tr, int l, int r, int bl, int b, int br) {
    int max = tl;
    if (t > max) {
        max = t;
    }
    if (tr > max) {
        max = tr;
    }
    if (l > max) {
        max = l;
    }
    if (r > max) {
        max = r;
    }
    if (bl > max) {
        max = bl;
    }
    if (b > max) {
        max = b;
    }
    if (br > max) {
        max = br;
    }
    return max;
}

int traverse(char a[50][50], int i, int j, int h, int w, int v[50][50], char prev) {
    if (i < 0
            || j < 0
            || i >= h
            || j >= w
       ) {
        return 0;
    }
    if (prev+1 != a[i][j]) {
        return 0;
    }
    if (v[i][j]) {
        return v[i][j];
    }
    int tl = 0, t = 0, tr = 0, l = 0, r = 0, bl = 0, b = 0, br = 0;
    tl = traverse(a, i-1, j-1, h, w, v, a[i][j]);
    t = traverse(a, i-1, j, h, w, v, a[i][j]);
    tr = traverse(a, i-1, j+1, h, w, v, a[i][j]);
    l = traverse(a, i, j-1, h, w, v, a[i][j]);
    r = traverse(a, i, j+1, h, w, v, a[i][j]);
    bl = traverse(a, i+1, j-1, h, w, v, a[i][j]);
    b = traverse(a, i+1, j, h, w, v, a[i][j]);
    br = traverse(a, i+1, j+1, h, w, v, a[i][j]);
    v[i][j] = getMax(tl, t, tr, l, r, bl, b, br) + 1;
    return v[i][j];
}

int getMaxPath(int h, int w) {
    // your code goes here
    char a[50][50];
    char before_a = (char)('A'-1);
    int v[50][50] = {0};
    for (int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    int max = 0, imidiate = 0;
    for (int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if (a[i][j] == 'A' && !v[i][j]) {
                imidiate = traverse(a, i, j, h, w, v, before_a);
                if (imidiate > max) {
                    max = imidiate;
                }
            }
        }
    }
    return max;
}

int main() {
    int h, w, max, c = 1;
    cin >> h >> w;
    while (h && w) {
        max = getMaxPath(h, w);
        cout << "Case " << c << ": " << max << endl;
        cin >> h >> w;
        c++;
    }
}
