#include <stdio.h>

typedef struct {
    char name[11];
    char gender;
    char id[11];
    int grade;
}Student;

int main(void) {
    int n;
    scanf("%d", &n);
    Student male_l, female_h;
    int l = 101, h = 0;
    int f = 0, m = 0;
    for (int i = 0; i < n; i++) {
        Student cur;
        scanf("%s %c %s %d", cur.name, &cur.gender, cur.id, &cur.grade);
        if (cur.gender == 'M' && cur.grade < l) {
            male_l = cur;
            l = male_l.grade;
            m = 1;
        } else if (cur.gender == 'F' && cur.grade > h) {
            female_h = cur;
            h = female_h.grade;
            f = 1;
        }
    }
    if (f) printf("%s %s\n", female_h.name, female_h.id);
    else printf("Absent\n");

    if (m) printf("%s %s\n", male_l.name, male_l.id);
    else printf("Absent\n");

    if (!f || !m) printf("NA");
    else printf("%d", female_h.grade - male_l.grade);
}