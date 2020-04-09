/*

Lik: https://www.hackerrank.com/challenges/counting-valleys/problem?
Input Format
The first line contains an integer , the number of steps in Gary's hike.
The second line contains a single string , of  characters that describe his path.
Output Format
Print a single integer that denotes the number of valleys Gary walked through during his hike.
Sample Input
8
UDDDUDUU
Sample Output
1
Explanation
If we represent _ as sea level, a step up as /, and a step down as \, Gary's hike can be drawn as:
_/\      _
   \    /
    \/\/
He enters and leaves one valley.

*/
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

int find_how_many_neg_in_array(int n, int *ar){
    int count = 0;
    int set = 0;
    for(int i = 0; i < n; ++i){
        if ((ar[i] * (-1)) > 0){
            if (set == 0){
                count++;
                set = 1;
            }
        } else {
            set = 0;
        }
    }

    return count;
}
// Complete the countingValleys function below.
int countingValleys(int n, char* s) {
    int mo_ar[n+1];
    mo_ar[0] = 0;
    for(int i = 0; i < n; ++i){
        if (s[i] == 'U')
            mo_ar[i+1] = mo_ar[i] + 1;
        else
            mo_ar[i+1] = mo_ar[i] - 1;
    }
    return find_how_many_neg_in_array(n+1, mo_ar);
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* s = readline();

    int result = countingValleys(n, s);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
