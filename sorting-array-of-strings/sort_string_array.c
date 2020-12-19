#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
	int i;
	for (i = 0; a[i] != '\0' && b[i] != '\0'; i++)
	{
		if (a[i] == b[i])
			continue;
		else if (a[i] < b[i]) {
			return 0;
		} else {
			return  1;
		}
	}
	if (b[i] == '\0')
		return 1;
	return 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
	int i;
	for (i = 0; a[i] != '\0' && b[i] != '\0'; i++)
	{
		if (a[i] == b[i])
			continue;
		else if (a[i] > b[i]) {
			return 0;
		} else {
			return  1;
		}
	}
	if (a[i] == '\0')
		return 1;
	return 0;
}

int ch_in_string(char *a, char c) {
	for (int i = 0; a[i] != '\0'; i++) {
		if (a[i] == c)
			return 1;
	}
	return 0;
}
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
	int alen;
	int acnt = 0;
	int blen;
	int bcnt = 0;
	int f = 0;
	char found[1024] ;
	memset(found, '\0' , 1024);
	for (alen = 0; a[alen] != '\0'; alen++) {
		if (!ch_in_string(found, a[alen])) {
			found[f++] = a[alen];
			acnt++;
		}
	}
	memset(found, '\0' , 1024);
	f = 0;
	for (blen = 0; b[blen] != '\0'; blen++) {
		if (!ch_in_string(found, b[blen])) {
			found[f++] = b[blen];
			bcnt++;
		}
	}
	if (acnt  == bcnt )
		return lexicographic_sort(a, b);
	if (acnt > bcnt)
		return 1;
	return 0;
}

int sort_by_length(const char* a, const char* b) {
	int alen;
	int blen;
	for (alen = 0; a[alen] != '\0'; alen++);
	for (blen = 0; b[blen] != '\0'; blen++);
	if (alen - 1 == blen -1)
		return lexicographic_sort(a, b);
	if (alen > blen)
		return 1;

	return 0;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
	for (int i = 0; i < len; i++)
	{
		for (int k = i+1; k < len; k++)
		{
			if (cmp_func(*(arr + i), *(arr+k))) {
				char *tmp=arr[i];
				arr[i] = arr[k];
				arr[k] = tmp;
			}
		}
	}
}



int main() 
{
	int n;
	scanf("%d", &n);

	char** arr;
	arr = (char**)malloc(n * sizeof(char*));

	for(int i = 0; i < n; i++){
		*(arr + i) = malloc(1024 * sizeof(char));
		scanf("%s", *(arr + i));
		*(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
	}

	string_sort(arr, n, lexicographic_sort);
	for(int i = 0; i < n; i++)
		printf("%s\n", arr[i]);
	printf("\n");

	string_sort(arr, n, lexicographic_sort_reverse);
	for(int i = 0; i < n; i++)
		printf("%s\n", arr[i]); 
	printf("\n");

	string_sort(arr, n, sort_by_length);
	for(int i = 0; i < n; i++)
		printf("%s\n", arr[i]);    
	printf("\n");

	string_sort(arr, n, sort_by_number_of_distinct_characters);
	for(int i = 0; i < n; i++)
		printf("%s\n", arr[i]); 
	printf("\n");
}
