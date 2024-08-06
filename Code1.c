int compareDescending(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);  
}
int minimumPushes(char *word) {
    int freq[26] = {0};  
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        freq[word[i] - 'a']++;
    }
    qsort(freq, 26, sizeof(int), compareDescending);
    int dig_used = 0, ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += ((dig_used / 8) + 1) * freq[i];
        dig_used++;
    }
    return ans;
}
