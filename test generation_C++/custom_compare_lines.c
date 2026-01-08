#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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
   
   // Parse scientific notation values from program output
   double a_po_base, b_po_base, c_po_base, d_po_base;
   int a_po_exp, b_po_exp, c_po_exp, d_po_exp;
   
   if (sscanf(line_program_output_lower, "%lfE%d %lfE%d %lfE%d %lfE%d", 
            &a_po_base, &a_po_exp, &b_po_base, &b_po_exp, 
            &c_po_base, &c_po_exp, &d_po_base, &d_po_exp) != 8) {
      free(line_program_output_lower);
      free(line_output_lower);
      return 0;
   }
   
   // Parse scientific notation values from expected output
   double a_o_base, b_o_base, c_o_base, d_o_base;
   int a_o_exp, b_o_exp, c_o_exp, d_o_exp;
   
   if (sscanf(line_output_lower, "%lfE%d %lfE%d %lfE%d %lfE%d", 
            &a_o_base, &a_o_exp, &b_o_base, &b_o_exp, 
            &c_o_base, &c_o_exp, &d_o_base, &d_o_exp) != 8) {
      free(line_program_output_lower);
      free(line_output_lower);
      return 0;
   }
   
   // Compare number by number
   int result = (a_po_base == a_o_base &&
               b_po_base == b_o_base &&
               c_po_base == c_o_base &&
               d_po_base == d_o_base &&
               a_po_exp == a_o_exp &&
               b_po_exp == b_o_exp &&
               c_po_exp == c_o_exp &&
               d_po_exp == d_o_exp);
   
   // Clean up allocated memory
   free(line_program_output_lower);
   free(line_output_lower);
   
   return result;
}
