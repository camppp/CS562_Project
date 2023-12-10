Net* dbNetwork::net(const Term* term) const {
  // Translate the Term object to a dbBTerm object using staToDb function
  dbBTerm* bterm = staToDb(term);

  // Get the dbNet object associated with the dbBTerm object
  dbNet* dnet = bterm->getNet();

  // Translate the dbNet object to a Net object using dbToSta function
  return dbToSta(dnet);
}
