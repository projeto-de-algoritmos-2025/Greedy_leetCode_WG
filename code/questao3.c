static int cmp_desc(const void* a, const void* b) {
    int va = *(const int*)a, vb = *(const int*)b;
    if (vb > va) return 1;
    if (vb < va) return -1;
    return 0;
}

int maxSatisfaction(int* satisfaction, int satisfactionSize) {
    if (satisfactionSize == 0) return 0;
    qsort(satisfaction, satisfactionSize, sizeof(int), cmp_desc);

    long long res = 0, prefix = 0;
    for (int i = 0; i < satisfactionSize; ++i) {
        if (prefix + satisfaction[i] <= 0) break;
        prefix += satisfaction[i];
        res += prefix;
    }
    return (int)res;
}