#include <stdio.h>
#include <ctype.h>
#define LEN 81

int main(void) {
	char right[LEN];
	char wrong[LEN];
	scanf("%s", right);
	scanf("%s", wrong);
	for (int i = 0; wrong[i] != '\0'; i++) {
		for (int j = 0; right[j] != '\0'; j++) {
			if (right[j] == wrong[i]) right[j] = '!';
		}
	} 
	for (int i = 0; right[i] != '\0'; i++) {
		int k = i + 1;
		while(right[k] != '\0') {
			if (toupper(right[k]) == toupper(right[i])) right[k] = '!';
			k++;
		}  
	}
	for (int i = 0; right[i] != '\0'; i++) {
		if (right[i] != '!') printf("%c", toupper(right[i]));
	}
}