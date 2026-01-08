#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    srand(time(NULL));
    
    int T = 100000;
    
    FILE *input_file = fopen("input.txt", "w");
    FILE *output_file = fopen("output.txt", "w");
    
    if (!input_file || !output_file) {
        printf("Error opening files\n");
        if (input_file) fclose(input_file);
        if (output_file) fclose(output_file);
        return 1;
    }
    
    fprintf(input_file, "%d\n", T);
    
    for (int t = 0; t < T; ++t) {
        // Generate random number between 10^13 and 10^14 - 1
        long long min_val = (long long)pow(10, 13);
        long long max_val = (long long)pow(10, 14) - 1;
        long long a = min_val + rand() % (max_val - min_val + 1);
        
        fprintf(input_file, "%lld\n", a);
        fprintf(output_file, "%c\n", (a % 11 == 0) ? 'C' : 'K');
    }
    
    fclose(input_file);
    fclose(output_file);
    
    return 0;
}
