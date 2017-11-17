#include <stdio.h>
#include <string.h>
int main(void) {
    int line;
    scanf("%d", &line);
    char str_map[line][100];
    char pat[3] = "PAT";
    int flag[line];
    int pos_P = -1;
    int pos_T = -1;
    int len = 0;

    for (int i = 0; i < line; i++) {
        scanf("%s", str_map[i]);
        int pat_appear[3] = {0, 0, 0};
        for(int j = 0; str_map[i][j] != '\0'; j++) {
            flag[i] = 1;
            len = strlen(str_map[i]);
            if(str_map[i][j] == 'P') {
                if(pat_appear[0] == 0) {
                    pat_appear[0] = 1;
                    pos_P = j;
                } else {
                    flag[i] = 0;
                }
            }
            if(str_map[i][j] == 'A') {
                pat_appear[1] = 1;
            }
            if(str_map[i][j] == 'T') {
                if(pat_appear[2] == 0) {
                    pat_appear[2] = 1;
                    pos_T = j;
                } else {
                    flag[i] = 0;
                }
            }
            if(str_map[i][j] != 'P' && str_map[i][j] != 'A' && str_map[i][j] != 'T') { 
                flag[i] = 0;
            }//没有除PAT之外的字符出现
        }
        if(pos_P != -1 && pos_T != -1) {
            if((len - 1 - pos_T) != (pos_P * (pos_T - pos_P - 1))) 
                flag[i] = 0; 
        }//A的个数规律
        if((!pat_appear[0]) || (!pat_appear[1]) || (!pat_appear[2])){
            flag[i] = 0;
        }////判断一下PAT都出现了而且P和T只出现一次
    }

    for (int k = 0; k < line; k++) {
        if(flag[k]) {
            printf("YES\n");//Yes是通不过的哦…
        } else { 
            printf("NO\n");
        }
    }
}