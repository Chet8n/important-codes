#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAX 54000
#define inf -1000000

int a[MAX + 1];

struct treeNode
{
    int psum;
    int ssum;
    int sum;
    int msum;


};

treeNode tree[3 * MAX + 1];

void buildTree(int index, int s, int e) {
    if (s == e) {
        tree[index] = ((treeNode) {a[s], a[s], a[s], a[s]});
        return;
    }

    int mid = (s + e) >> 1;
    buildTree(2 * index + 1, s, mid);
    buildTree(2 * index + 2, mid + 1, e);

    treeNode left = tree[2 * index + 1];
    treeNode right = tree[2 * index + 2];
    tree[index].psum = max(left.psum, left.sum + right.psum);
    tree[index].ssum = max(right.ssum, right.sum + left.ssum);
    tree[index].sum = left.sum + right.sum;
    tree[index].msum = max(left.ssum + right.psum, max(left.msum, right.msum));

    return;
}

treeNode query(int index, int s, int e, int i, int j) {

    //complete overlap:
    if (s >= i and e <= j) {
        return tree[index];
    }

    // no overlap:
    if (s > j or e < i) {
        return ((treeNode) {inf, inf, inf, inf});
    }

    //Partial Overlap:
    int mid = (s + e) >> 1;
    treeNode left = query(2 * index + 1, s, mid, i, j);
    treeNode right = query(2 * index + 2, mid + 1, e, i, j);

    treeNode temp;
    temp.psum = max(left.psum, left.sum + right.psum);
    temp.ssum = max(right.ssum, right.sum + left.ssum);
    temp.sum = left.sum + right.sum;
    temp.msum = max(left.ssum + right.psum, max(left.msum, right.msum));

    return temp;

}



int32_t main()
{

    IOS

    int n, m, t, x, y;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    buildTree(0, 0, n - 1);

    cin >> m;
    for(int i = 0;i < m;i++){
        cin >> x >> y;
        cout << query(0,0,n-1,x-1,y-1).msum << endl;
    }


    return 0;

}
