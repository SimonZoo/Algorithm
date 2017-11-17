//from Internet
#include <stdio.h>
#include <string.h>
#define LEN 7
#define B 3

int main(void) {
	int n;
    scanf("%d", &n);
    char name[LEN];
    int year, month, day, count = 0;
    int maxyear = 0, maxmonth = 0, maxday = 0, minyear = 9999, minmonth = 99, minday = 99;
    char maxname[LEN];
    char minname[LEN];
    for (int i = 0; i < n; i++) {
        scanf("%s", name);
        scanf("%d/%d/%d",&year, &month, &day);
        if((year < 2014 || (year == 2014 && month < 9) || (year == 2014 && month == 9 && day <= 6)) &&
           (year > 1814 || (year == 1814 && month > 9) || (year == 1814 && month == 9 && day >= 6))) {
            count++;
            if(year > maxyear || (year == maxyear && month > maxmonth) || (year == maxyear && month == maxmonth && day > maxday)) {
                maxyear = year;
                maxmonth = month;
                maxday = day;
                strcpy(maxname, name);
            }
            if(year < minyear || (year == minyear && month < minmonth) || (year == minyear && month == minmonth && day < minday)) {
                minyear = year;
                minmonth = month;
                minday = day;
                strcpy(minname, name);
            }
        }
    }
    if (count != 0) {
        printf("%d ", count);
        printf("%s %s", minname, maxname);
    } else {
        printf("%d", count);
    }
    return 0;
}