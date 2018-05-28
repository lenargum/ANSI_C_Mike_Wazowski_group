#include <stdio.h>
#include <string.h>
#include <malloc.h>

char *flush(const char input[]) {
	//ща насру кодом
	char *result = malloc(sizeof(input));
	char isComment = 'n';
	int resultLastIndex = 0;

	for (int i = 0; i < strlen(input); i++) {
		switch (isComment) {
			case 'n':
				if (input[i] != '/') {
					result[resultLastIndex] = input[i];
					resultLastIndex++;
					continue;
				} else {
					if (i + 1 < strlen(input)) {
						switch (input[i + 1]) {
							case '*':
								isComment = 'l';
								i++;
								break;
							case '/':
								isComment = 's';
								i++;
								break;
							default:
								result[resultLastIndex] = input[i];
								resultLastIndex++;
						}
					}
				}
				break;
			case 'l':
				if (input[i] == '*' && i + 1 < strlen(input) && input[i + 1] == '/') {
					isComment = 'n';
					i++;
				}
				break;
			case 's':
				if (input[i] == '\n') {
					isComment = 'n';
				}
				break;
		}
	}
	return result;
}


int main() {
	char temp[] = "doljno /* ne doljno */ doljno\n//ne doljno\n doljno\' doljno \ndoljno";
	// "ya  tvou
	//   mamashu v kino vodil
	//  jest"
	printf("%s", flush(temp));
	return 0;
}