Net* dbNetwork::net(const Term* term) const
{
    // Convert the Term object to a dbBTerm object
    dbBTerm* db_term = staToDb(term);

    // Get the Net object corresponding to the dbBTerm object
    dbNet* dnet = db_term->getNet();

    // Convert the dbNet object to a Net object
    Net* net = dbToSta(dnet);

    return net;
}
