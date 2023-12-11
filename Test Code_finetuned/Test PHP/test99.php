class User {
    private $idUser;

    /**
     * @param int $idUser
     */
    public function setIdUser($idUser) {
        $this->idUser = $idUser;
    }

    /**
     * @return int
     */
    public function getIdUser() {
        return $this->idUser;
    }

    /**
     * @return User
     */
    public function getUser() {
        return $this;
    }
}