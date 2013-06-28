#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
 
int levenshtein(char *s1, char *s2) {
    unsigned int s1len, s2len, x, y, lastdiag, olddiag;
    s1len = strlen(s1);
    s2len = strlen(s2);
    unsigned int column[s1len+1];
    for (y = 1; y <= s1len; y++)
        column[y] = y;
    for (x = 1; x <= s2len; x++) {
        column[0] = x;
        for (y = 1, lastdiag = x-1; y <= s1len; y++) {
            olddiag = column[y];
            column[y] = MIN3(column[y] + 1, column[y-1] + 1, lastdiag + (s1[y-1] == s2[x-1] ? 0 : 1));
            lastdiag = olddiag;
        }
    }
    return(column[s1len]);
}

int main(int argc, char *argv[]) {
	
	if (argc < 3) {
		printf("Cyle's Magic Levenshtein distance calculator.\n");
		printf("This expects either two arguments, each a file name, to compare, or a -v before them for verbose output.\n");
		printf("Exmaple 1: ./filediff text1.txt text2.txt \n");
		printf("Exmaple 2: ./filediff -v text1.txt text2.txt \n");
		return 1;
	}
	
	int verbose = 0;
	char *filename_one;
	char *filename_two;
	
	if (strncmp("-v", argv[1], 2) == 0) {
		verbose = 1;
		filename_one = argv[2];
		filename_two = argv[3];
	} else {
		filename_one = argv[1];
		filename_two = argv[2];
	}
	
	//printf("Filename 1: %s, filename 2: %s", filename_one, filename_two);
	
	char *file_one_contents;
	char *file_two_contents;
	
	long input_file_one_size;
	long input_file_two_size;
	
	FILE *input_file_one = fopen(filename_one, "rb");
	fseek(input_file_one, 0, SEEK_END);
	input_file_one_size = ftell(input_file_one);
	rewind(input_file_one);
	file_one_contents = malloc(input_file_one_size * (sizeof(char)));
	fread(file_one_contents, sizeof(char), input_file_one_size, input_file_one);
	fclose(input_file_one);
	
	FILE *input_file_two = fopen(filename_two, "rb");
	fseek(input_file_two, 0, SEEK_END);
	input_file_two_size = ftell(input_file_two);
	rewind(input_file_two);
	file_two_contents = malloc(input_file_two_size * (sizeof(char)));
	fread(file_two_contents, sizeof(char), input_file_two_size, input_file_two);
	fclose(input_file_two);
	
	int diff = levenshtein(file_one_contents, file_two_contents);
	if (verbose == 1) {
		printf("Difference between %s and %s: %i \n", filename_one, filename_two, diff);
	} else {
		printf("%i\n", diff);
	}
	
	return 0;
}
