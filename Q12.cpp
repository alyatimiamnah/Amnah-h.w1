/*
  Write a C++ program that uses if / else if / else:

  1) Input two numbers:
  - momentum p (GeV/c)
  - mass m (GeV/c^2)

  2) Compute the relativistic energy:
   E = sqrt(p*p + m*m)

  3) Classify the energy:
   - if E > 5 print "High energy particle"
   - else if E == 5 print "Medium energy particle"
   - else print "Low energy particle"
  4) Print the value of E and the classification.
*/


void Q12() {

  double p = 3.0;   // momentum
  double m = 4.0;   // mass
  double E;

  E = sqrt(p*p + m*m);

  std::cout << "Energy E = " << E << std::endl;

  if (E > 5) {
    std::cout << "High energy particle" << std::endl;
  }
  else if (E == 5) {
    std::cout << "Medium energy particle" << std::endl;
  }
  else {
    std::cout << "Low energy particle" << std::endl;
  }
}
