const int N = 100010;
int n, m, tt, heap[N];

void up(int p) {
    while (p > 1) {
        if (heap[p] < heap[p / 2]) {
            swap(heap[p], heap[p / 2]);
            p /= 2;
        }
        else break;
    }
}

void down(int p) {
    int s = p * 2;
    while (s <= tt) {
        if (s < tt && heap[s] > heap[s + 1]) s++;
        if (heap[s] < heap[p]) {
            swap(heap[s], heap[p]);
            p = s;
            s = p * 2;
        }
        else break;
    }
}

void remove1() {
    heap[1] = heap[tt--];
    down(1);
}

void insert(int x) {
    heap[++tt] = x;
    up(tt);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> heap[i];
        insert(heap[i]);
    }
    for (int i = 1; i <= m; i++) {
        cout << heap[1] << ' ';
        remove1();
    }
    return 0;
}
