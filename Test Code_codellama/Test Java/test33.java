public void addReceive(ReceiveVO receiveVO) {
    // Retrieve the user associated with the receive operation
    User user = userDao.getUserByAccount(receiveVO.getAccount());

    // Set the receive date from the ReceiveVO object
    receiveVO.setReceiveDate(new Date());

    // Create a new Receive entity with the user and receive date
    Receive receive = new Receive();
    receive.setUser(user);
    receive.setReceiveDate(receiveVO.getReceiveDate());

    // Add the receive entity to the database
    receiveDao.addReceive(receive);
}