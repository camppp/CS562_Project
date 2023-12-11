class Project {
    private $beginDate;

    public function setBeginAt($beginDate) {
        if (!$this->isValidDate($beginDate)) {
            throw new InvalidArgumentException("Invalid date format. Please use 'YYYY-MM-DD'.");
        }

        $this->beginDate = $beginDate;
    }

    private function isValidDate($date) {
        $dateTime = date_create($date);
        return $dateTime && date_format($dateTime, 'Y-m-d') == $date;
    }
}