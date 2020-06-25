#include <limits>
#include <iostream>
#include <ios>
#include <fstream>
#include <string>
#include <vector>

int main ( int argc, char **argv )
{
  if (argc < 3 || argc > 4) {
    std::cerr << "Usage: pmenc <infile> <outfile> <password>" << std::endl;
    return 1;
  }

  std::vector<std::string> inargs;
  inargs.assign(argv + 1, argv + argc);
  std::string infile = inargs[0];
  std::string outfile = inargs[1];
  std::string password = "No password given";
  if (argc == 4) {
    password = inargs[2];
    password += "00000000";
    password = password.substr(0,8);
  }

  std::cout << "Num args: " << inargs.size() << std::endl;
  std::cout << "input file: " << infile << std::endl;
  std::cout << "Output file: " << outfile << std::endl;
  std::cout << "Password: " << password << std::endl;

  // Open input file
  std::ifstream ifile;
  ifile.open(infile, std::ios::in|std::ios::binary);
  if (!ifile.good()) {
    std::cerr << "Failed to open file " << infile << std::endl;
    return 1;
  }

  // Get input file size in bytes
  ifile.ignore( std::numeric_limits<std::streamsize>::max() );
  std::streamsize length = ifile.gcount();
  ifile.clear();   //  Since ignore will have set eof.
  ifile.seekg( 0, std::ios_base::beg );
  ifile.close();
  std::cout << "File size in bytes: " << length << std::endl;

  // Get password
  std::cout << "Password size: " << password.size() << std::endl;
  char scramb[8] = {0,0,0,0,0,0,0,0};
  if (argc == 4) {
    for (unsigned int ii = 0; ii < password.size(); ++ii) {
      scramb[ii] = password[ii];
    }
  }
  std::cout << "Scrambling integer: ";
  for (int kk = 0; kk < 8; ++kk) {
    std::cout << scramb[kk];
  }
  std::cout << std::endl;

  // Open input file for read
  ifile.open(infile, std::ios::in|std::ios::binary);
  if (!ifile.good()) {
    std::cerr << "Failed to open file " << infile << " for scrambling" << std::endl;
    return 1;
  }

  // Open output file for write
  std::ofstream ofile;
  ofile.open(outfile, std::ios::out|std::ios::binary);
  if (!ofile.is_open()) {
    std::cerr << "Failed to open file " << outfile << std::endl;
    return 1;
  }

  // Scramble
  long sz = 1;
  char buffer;
  int kk = length;
  char scrambled;
  int jj =0;
  while (kk > 0) {
    ifile.read(&buffer, sz);
    scrambled = buffer ^ scramb[kk % 8]; 
    ofile.write(&scrambled, sz);
    kk -= 1;
    jj += 1;
  }

  ofile.close();
  ifile.close();

  std::cout << "Wrote " << jj << " bytes to output file" << std::endl;

  return 0;
}
