double getMyEtaRegion(const std::string& etaRegion) {
  double myEtaRegion = FixedGridEnergyDensity::Central;
  if (etaRegion == "Central") {
    myEtaRegion = FixedGridEnergyDensity::Central;
  } else if (etaRegion == "Forward") {
    myEtaRegion = FixedGridEnergyDensity::Forward;
  } else if (etaRegion == "All") {
    myEtaRegion = FixedGridEnergyDensity::All;
  } else {
    std::cerr << "Warning: Unrecognized EtaRegion value: " << etaRegion << std::endl;
  }
  return myEtaRegion;
}
