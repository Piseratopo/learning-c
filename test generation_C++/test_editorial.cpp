#include <chrono>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

bool compareSimilarLines(const string& line1, const string& line2) {
   return line1 == line2;
}

bool compareNumbersOnLines(const string& line1, const string &line2, double threshold) {
   vector<string> numbers1, numbers2;
   istringstream iss1(line1), iss2(line2);
   string number;
   while (getline(iss1, number, ' ')) numbers1.push_back(number);
   while (getline(iss2, number, ' ')) numbers2.push_back(number);

   if (numbers1.size() != numbers2.size()) return false;

   for (int i = 0; i < numbers1.size(); ++i) {
      double a = stod(numbers1[i]), b = stod(numbers2[i]);
      if (abs(a - b) > threshold) return false;
   }
   
   return true;
}

bool customCompare(const string& line1, const string& line2) {
   try {
      return compareSimilarLines(line1, line2) || compareNumbersOnLines(line1, line2, 0.01);
   } catch (const std::exception& e) {
      return false;
   }
}

bool compareFiles(const string& file1, const string& file2) {
   ifstream f1(file1);
   ifstream f2(file2);

   if (!f1.is_open() || !f2.is_open()) {
      return false;
   }

   string line1, line2;
   while (getline(f1, line1) && getline(f2, line2)) {
      if (!customCompare(line1, line2)) {
         cout << "Line mismatch: " << line1 << " vs " << line2 << endl;
         return false;
      }
   }

   // Check if one file has more lines than the other
   if (getline(f1, line1) || getline(f2, line2)) {
      cout << "File length mismatch" << endl;
      return false;
   }

   return true;
}

void printFileContents(const string& filename) {
   ifstream file(filename);
   if (file.is_open()) {
      string line;
      while (getline(file, line)) {
         cout << line << endl;
      }
   }
}

void grade_program(const string& program_file, const string& input_file = "input.txt",
                   const string& expected_output_file = "output.txt") {
   // Determine compiler based on file extension
   string compiler;
   if (program_file.find(".cpp") != string::npos) {
      compiler = "g++";
   } else if (program_file.find(".c") != string::npos) {
      compiler = "gcc";
   } else {
      cout << "Unsupported file type. Please provide a .c or .cpp file." << endl;
      return;
   }

   string executable = "editorial";
#ifdef _WIN32
   executable += ".exe";
#endif

   // Step 1: Compile the program
   string compile_cmd = compiler + " " + program_file + " -o " + executable;
   cout << "Compiling: " << compile_cmd << endl;

   int compile_result = system(compile_cmd.c_str());
   if (compile_result != 0) {
      cout << "Compilation failed." << endl;
      return;
   }
   cout << "Compilation successful." << endl;

   // Step 2: Run the program with input.txt
   string run_cmd;
#ifdef _WIN32
   run_cmd = executable + " < " + input_file + " > program_output.txt";
#else
   run_cmd = "./" + executable + " < " + input_file + " > program_output.txt";
#endif
   cout << "Running: " << run_cmd << endl;

   auto start_time = chrono::high_resolution_clock::now();
   int run_result = system(run_cmd.c_str());
   auto end_time = chrono::high_resolution_clock::now();
   chrono::duration<double> run_time = end_time - start_time;
   if (run_result != 0) {
      cout << "Execution failed." << endl;
      return;
   }
   cout << "Execution successful. Time taken: " << run_time.count() << " seconds." << endl;

   // Step 3: Compare output with expected output
   if (compareFiles("program_output.txt", expected_output_file)) {
      cout << "ACCEPTED: Output matches expected output." << endl;
   } else {
      cout << "WRONG ANSWER: Output does not match expected output." << endl;
   }
}

int main(int argc, char* argv[]) {
   if (argc < 2) {
      cout << "Usage: " << argv[0] << " <program.c|program.cpp>" << endl;
      return 1;
   }

   string program_file = argv[1];
   grade_program(program_file);

   return 0;
}
