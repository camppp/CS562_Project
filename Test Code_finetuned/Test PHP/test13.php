class Conference {
    private $db;

    public function __construct($db) {
        $this->db = $db;
    }

    public function getAllConf() {
        $query = "SELECT id, configuration FROM conferences";
        $result = $this->db->query($query);

        $confres = [];
        while ($row = $result->fetch_assoc()) {
            $confres['conf'. $row['id']] = $row['configuration'];
        }

        return $confres;
    }
}