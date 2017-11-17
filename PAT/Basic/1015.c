#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int de;
    int cai;        
} Student;
int cmp(const void *p1, const void *p2) {
    Student *a = (Student*) p1;
    Student *b = (Student*) p2;
    if (a -> de + a -> cai != b -> de + b -> cai) 
        return (b -> de + b -> cai) > (a -> de + a -> cai) ? 1 : -1;
    else if (a -> de != b -> de) 
        return b -> de > a -> de ? 1 : -1;
    else 
        return a -> id > b -> id ? 1 : -1;
}
int main(void) {
    int n, low, high;
    scanf("%d %d %d", &n, &low,&high);
    Student A[n];
    Student B[n];
    Student C[n];
    Student D[n];
    int arrNum[4] = {0};
    for (int i = 0; i < n; i++) {
        Student s;
        scanf("%d %d %d", &s.id, &s.de, &s.cai);
        if (s.de >= high && s.cai >= high) {
            A[arrNum[0]] = s;
            arrNum[0]++;
        }
        else if(s.de >= high && s.cai >= low) {
            B[arrNum[1]] = s;
            arrNum[1]++;
        }
        else if(s.de >= low && s.cai >= low && s.de >= s.cai) {
            C[arrNum[2]] = s;
            arrNum[2]++;
        }
        else if (s.de >= low && s.cai >= low) {
            D[arrNum[3]] = s;
            arrNum[3]++;
        }
    }
    qsort(A, arrNum[0], sizeof(A[0]), cmp);
    qsort(B, arrNum[1], sizeof(A[0]), cmp);
    qsort(C, arrNum[2], sizeof(A[0]), cmp);
    qsort(D, arrNum[3], sizeof(A[0]), cmp);
    printf("%d\n", arrNum[0] + arrNum[1] + arrNum[2] + arrNum[3]);
    for (int i = 0; i < arrNum[0]; i++) {
        printf("%d %d %d\n", A[i].id, A[i].de, A[i].cai);
    }
    for (int i = 0; i < arrNum[1]; i++) {
        printf("%d %d %d\n", B[i].id, B[i].de, B[i].cai);
    }
    for (int i = 0; i < arrNum[2]; i++) {
        printf("%d %d %d\n", C[i].id, C[i].de, C[i].cai);
    }
    for (int i = 0; i < arrNum[3]; i++) {
        printf("%d %d %d\n", D[i].id, D[i].de, D[i].cai);
    }
}