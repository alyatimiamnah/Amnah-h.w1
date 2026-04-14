/*Q8
  Write a C++ program that:

  1. Read Data:
     Write a function read_from_file(filename) that reads a text file
        containing particle physics data and returns each line as a string.

        2. Main Program:
           - Use read_from_file("particle_data.txt") to read the file.
              - Print each particle physics entry to the screen.
                 - Make sure the file is read correctly.
*/

void read_from_file(std::string filename) {

  std::ifstream file(filename);
  std::string line;

  if (file.is_open()) {

    while (getline(file, line)) {
      std::cout << line << std::endl;
    }

    file.close();
  }
  else {
    std::cout << "Error: file not found" << std::endl;
  }
}

void Q8() {

  read_from_file("particle_data.txt");
}
