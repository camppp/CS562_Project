void calculateYIonMZs(const string& peptideSequence, vector<double>& vvdYionMass) {
  // Check if the sizes of vvdYionMass and vvdBionMass are equal to iPeptideLength - 1
  if (vvdYionMass.size() != iPeptideLength - 1) {
    cout << "Error: The size of vvdYionMass is not equal to iPeptideLength - 1" << endl;
    return;
  }

  // Calculate the MZs of y ion fragments
  for (int i = 0; i < iPeptideLength - 1; i++) {
    vvdYionMass[i] = (vvdYionMass[i] + 1) / 1;
  }
}
