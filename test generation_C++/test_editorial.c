#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

// === Header of file ===

int customCompareLines(const char* line_program_output, const char* line_output, const char* line_input) {
   // Convert program output to lowercase
   char* line_program_output_lower = strdup(line_program_output);
   if (!line_program_output_lower) return 0;
   
   for (int i = 0; line_program_output_lower[i]; i++) {
      line_program_output_lower[i] = tolower(line_program_output_lower[i]);
   }
   
   // Convert expected output to lowercase
   char* line_output_lower = strdup(line_output);
   if (!line_output_lower) {
      free(line_program_output_lower);
      return 0;
   }
   
   for (int i = 0; line_output_lower[i]; i++) {
      line_output_lower[i] = tolower(line_output_lower[i]);
   }
   
   int a_po_base_int, a_po_base_decimal, b_po_base_int, b_po_base_decimal, c_po_base_int, c_po_base_decimal, d_po_base_int, d_po_base_decimal;
   int a_po_exp, b_po_exp, c_po_exp, d_po_exp;
   int a_o_base_int, a_o_base_decimal, b_o_base_int, b_o_base_decimal, c_o_base_int, c_o_base_decimal, d_o_base_int, d_o_base_decimal;
   int a_o_exp, b_o_exp, c_o_exp, d_o_exp;

   // Parse scientific notation values from program output
   if (sscanf(line_program_output_lower, "%d.%de%d %d.%de%d %d.%de%d %d.%de%d", 
            &a_po_base_int, &a_po_base_decimal, &a_po_exp, &b_po_base_int, &b_po_base_decimal, &b_po_exp, 
            &c_po_base_int, &c_po_base_decimal, &c_po_exp, &d_po_base_int, &d_po_base_decimal, &d_po_exp) != 12) {
      printf("Error[1]: failed to parse scientific notation for program output.\n");
      printf("%s\n", line_program_output_lower);
      free(line_program_output_lower);
      free(line_output_lower);
      return 0;
   }
   
   // Parse scientific notation values from expected output
   if (sscanf(line_output_lower, "%d.%de%d %d.%de%d %d.%de%d %d.%de%d", 
            &a_o_base_int, &a_o_base_decimal, &a_o_exp, &b_o_base_int, &b_o_base_decimal, &b_o_exp, 
            &c_o_base_int, &c_o_base_decimal, &c_o_exp, &d_o_base_int, &d_o_base_decimal, &d_o_exp) != 12) {
      printf("Error[2]: failed to parse scientific notation for expected output.\n");
      free(line_program_output_lower);
      free(line_output_lower);
      return 0;
   }

   
   // Compare number by number
   int result = (a_po_base_int == a_o_base_int &&
               a_po_base_decimal == a_o_base_decimal &&
               a_po_exp == a_o_exp &&
               b_po_base_int == b_o_base_int &&
               b_po_base_decimal == b_o_base_decimal &&
               b_po_exp == b_o_exp &&
               c_po_base_int == c_o_base_int &&
               c_po_base_decimal == c_o_base_decimal &&
               c_po_exp == c_o_exp &&
               d_po_base_int == d_o_base_int &&
               d_po_base_decimal == d_o_base_decimal &&
               d_po_exp == d_o_exp);
   
   if (!result) {
      printf("WRONG ANSWER: Error more than threshold.");
      printf("Input: %s\n", line_input);
      printf("Output: %s\n", line_program_output);
   }
   
   // Clean up allocated memory
   free(line_program_output_lower);
   free(line_output_lower);
   
   return result;
}

// === Footer of file ===

int compareFiles(const char* program_output, const char* output, const char* input) {
   FILE* f1 = fopen(program_output, "r");
   FILE* f2 = fopen(output, "r");
   FILE* fi = fopen(input, "r");

   if (!f1 || !f2 || !fi) {
      if (f1) fclose(f1);
      if (f2) fclose(f2);
      if (fi) fclose(fi);
      return 0;
   }

   char line_program_output[1024];
   char line_output[1024];
   char line_input[1024];
   
   // Read first line from input
   if (!fgets(line_input, sizeof(line_input), fi)) {
      fclose(f1);
      fclose(f2);
      fclose(fi);
      return 0;
   }
   
   // Remove newline from input
   line_input[strcspn(line_input, "\n")] = '\0';
   
   while (fgets(line_program_output, sizeof(line_program_output), f1) &&
         fgets(line_output, sizeof(line_output), f2) &&
         fgets(line_input, sizeof(line_input), fi)) {
      
      // Remove newlines
      line_program_output[strcspn(line_program_output, "\n")] = '\0';
      line_output[strcspn(line_output, "\n")] = '\0';
      line_input[strcspn(line_input, "\n")] = '\0';
      
      if (!customCompareLines(line_program_output, line_output, line_input)) {
         fclose(f1);
         fclose(f2);
         fclose(fi);
         return 0;
      }
   }

   // Check if one file has more lines than the other
   if (fgets(line_program_output, sizeof(line_program_output), f1) ||
      fgets(line_output, sizeof(line_output), f2)) {
      printf("File length mismatch\n");
      fclose(f1);
      fclose(f2);
      fclose(fi);
      return 0;
   }

   fclose(f1);
   fclose(f2);
   fclose(fi);
   return 1;
}

void printFileContents(const char* filename) {
   FILE* file = fopen(filename, "r");
   if (file) {
      char line[1024];
      while (fgets(line, sizeof(line), file)) {
         printf("%s", line);
      }
      fclose(file);
   }
}

double getCurrentTime() {
#ifdef _WIN32
   LARGE_INTEGER frequency;
   LARGE_INTEGER now;
   QueryPerformanceFrequency(&frequency);
   QueryPerformanceCounter(&now);
   return (double)now.QuadPart / frequency.QuadPart;
#else
   struct timeval tv;
   gettimeofday(&tv, NULL);
   return tv.tv_sec + tv.tv_usec / 1000000.0;
#endif
}

void grade_program(
   const char* program_file,
   const char* input_file,
   const char* expected_output_file
) {
   // Use default values if NULL
   if (!input_file) input_file = "input.txt";
   if (!expected_output_file) expected_output_file = "output.txt";
   
   // Determine compiler based on file extension
   const char* compiler;
   if (strstr(program_file, ".cpp")) {
      compiler = "g++";
   } else if (strstr(program_file, ".c")) {
      compiler = "gcc";
   } else {
      printf("Unsupported file type. Please provide a .c or .cpp file.\n");
      return;
   }

   char executable[256];
   strcpy(executable, "editorial");
#ifdef _WIN32
   strcat(executable, ".exe");
#endif

   // Step 1: Compile the program
   char compile_cmd[512];
   snprintf(compile_cmd, sizeof(compile_cmd), "%s %s -o %s", compiler, program_file, executable);
   printf("Compiling: %s\n", compile_cmd);

   int compile_result = system(compile_cmd);
   if (compile_result != 0) {
      printf("Compilation failed.\n");
      return;
   }
   printf("Compilation successful.\n");

   // Step 2: Run the program with input.txt
   char run_cmd[512];
#ifdef _WIN32
   snprintf(run_cmd, sizeof(run_cmd), "%s < %s > program_output.txt", executable, input_file);
#else
   snprintf(run_cmd, sizeof(run_cmd), "./%s < %s > program_output.txt", executable, input_file);
#endif
   printf("Running: %s\n", run_cmd);

   double start_time = getCurrentTime();
   int run_result = system(run_cmd);
   double end_time = getCurrentTime();
   double run_time = end_time - start_time;
   
   if (run_result != 0) {
      printf("Execution failed.\n");
      return;
   }
   printf("Execution successful. Time taken: %.6f seconds.\n", run_time);

   // Step 3: Compare output with expected output
   if (compareFiles("program_output.txt", expected_output_file, input_file)) {
      printf("ACCEPTED\n");
   } else {
      printf("WRONG ANSWER\n");
   }
}

int main(int argc, char* argv[]) {
   if (argc < 2) {
      printf("Usage: %s <program.c|program.cpp>\n", argv[0]);
      return 1;
   }

   grade_program(argv[1], NULL, NULL);

   return 0;
}
