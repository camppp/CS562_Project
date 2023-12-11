public class ReceiveService {

    private UserDao userDao;
    private ReceiveDao receiveDao;

    public ReceiveService(UserDao userDao, ReceiveDao receiveDao) {
        this.userDao = userDao;
        this.receiveDao = receiveDao;
    }

    public void addReceive(ReceiveVO receiveVO) {
        User user = userDao.getUserByAccount(receiveVO.getUserName());
        if (user == null) {
            throw new IllegalArgumentException("User not found");
        }

        Receive receive = new Receive();
        receive.setUser(user);
        receive.setReceiveDate(receiveVO.getReceiveDate());
        // Perform additional operations if needed

        receiveDao.addReceive(receive);
    }
}