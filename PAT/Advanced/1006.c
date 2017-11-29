#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    char id[16], in_id[16], out_id[16];
    char in_time[9], out_time[9];
    char early[9] = "99:99:99";
    char late[9] = "00:00:00";
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%s%s", id, in_time, out_time);
        if (strcmp(early, in_time) > 0) { // early > in_time
            strcpy(in_id, id);
            strcpy(early, in_time);
        } 
        if (strcmp(late, out_time) < 0) {
            strcpy(out_id, id);
            strcpy(late, out_time);
        }
    }
    printf("%s %s", in_id, out_id);
}