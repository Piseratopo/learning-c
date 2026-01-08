bool customCompareLines(const string& line1, const string& line2, const string& line_i) {
   stringstream ss1(line1);
   double x, y, z;
   ss1 >> x >> y >> z;

   stringstream ssi(line_i);
   double a, b, c;
   ssi >> a >> b >> c;
   if (fabs(x + y - a) > 10e-2 || fabs(y - z - b) > 10e-2 || fabs(z / x - c) > 10e-2) {
      cout << "WRONG ANSWER: Error more than threshold.";
      cout << "Input: " << line_i << endl;
      cout << "Output: " << line1 << endl;
      return false;
   }
   return true;
}

bool compareFiles(const string& program_output, const string& output, const string& input) {
   ifstream f1(program_output);
   ifstream f2(output);
   ifstream fi(input);

   if (!f1.is_open() || !f2.is_open() || !fi.is_open()) {
      return false;
   }

   string line1, line2, line_i;
   getline(fi, line_i);
   while (getline(f1, line1) && getline(f2, line2) && getline(fi, line_i)) {
      if (line1 == line2) {
         continue;
      }
      if (!customCompareLines(line1, line2, line_i)) {
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