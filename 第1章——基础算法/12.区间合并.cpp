#define l first
#define r second
typedef pair<int,int> PII;
// 将所有存在交集的区间合并
vector<PII> merge(vector<PII> &segs) {
    vector<PII> ans;
    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    for (auto seg : segs) {
        if (ed < seg.l) {
            if (st != -2e9) ans.push_back({st, ed});
            st = seg.l, ed = seg.r;
        }
        else ed = max(ed, seg.r);
    }
    if (st != -2e9) ans.push_back({st, ed});
    return ans;
}
