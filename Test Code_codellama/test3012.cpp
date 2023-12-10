void calculateSurveyValues(const string& datatype, double sa0, double sa, double alpha, double vol, double fran, int nden, int np, const vector<double>& w, const vector<double>& bg, double norm, double pshot, double zmin, double zmax, const vector<double>& zwei, const vector<double>& nzwei, const vector<double>& z) {
  if (datatype.starts_with('d')) {
    sa0 = sa;
  } else if (datatype.starts_with('r')) {
    vol = fran * utils::invsum(zwei, nzwei);
    cout << "survey volume: " << vol << endl;
    norm = alpha * utils::sqsum_wei(w, nden) / utils::sqsum_div(w, bg, np);
    cout << "normalization: " << norm << endl;
    pshot = alpha * utils::sqsum_wei(w, nden) / utils::sqsum_div(w, bg, np);
    cout << "P_shot: " << pshot << endl;
    utils::zweight(z, zmin, zmax, zwei, nzwei);
  }
}
