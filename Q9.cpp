/*imple C++ programs: 1) FOR loop: - Print the numbers from 1 to 10 using a for loop. 2) WHILE loop:
-
Input integers from the user using a while loop. - Stop when the user enters 0. - Print how many numbers were entered (not counting 0). */


/*   void Q9() {

  int i;

  std::cout << "Using FOR loop:" << std::endl;

       for (i = 1; i <= 10; i++) {
        std::cout << i << std::endl;
         }
         } */



void Q9() {

  int numbers[] = {5, 8, 3, 0};  // 0 means stop
  int i = 0;
  int count = 0;

  std::cout << "Using WHILE loop:" << std::endl;

  while (numbers[i] != 0) {

    std::cout << numbers[i] << std::endl;
    count++;
    i++;
  }

  std::cout << "Total numbers entered (excluding 0) = "
            << count << std::endl;
}
