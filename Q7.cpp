
/*
  Q7
  Write a C++ program that:

  1. Create Data:
  Create a list of strings with particle physics information
  (e.g. electron, muon, pion masses).

  2. Save Data:
  Write a function save_to_file(data, filename) that writes
  each string to a new line in a text file.

  3. Main Program:
  Use save_to_file(data, "particle_data.txt") to create the file
  and store the particle data.
*/


void save_to_file(std::string data[], int size) {

  std::ofstream file("particle_data.txt");

  for (int i = 0; i < size; i++) {
    file << data[i] << std::endl;
  }

  file.close();
}

void Q7() {

  std::string data[3] = { "Electron mass = 0.511 MeV","Muon mass = 105.66 MeV", "Pion mass = 139.57 MeV" };

  save_to_file(data, 3);

  std::cout << "Saved." << std::endl;
}
