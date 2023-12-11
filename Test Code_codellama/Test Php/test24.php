class Project
{
    private $beginDate;

    public function setBeginAt($beginDate)
    {
        if (!$this->isValidDate($beginDate)) {
            throw new InvalidArgumentException("Invalid start date format. Expected format: YYYY-MM-DD");
        }

        $this->beginDate = $beginDate;
    }

    private function isValidDate($date)
    {
        $dateParts = explode('-', $date);
        if (count($dateParts) !== 3) {
            return false;
        }

        $year = (int) $dateParts[0];
        $month = (int) $dateParts[1];
        $day = (int) $dateParts[2];

        if ($year < 1 || $year > 9999) {
            return false;
        }

        if ($month < 1 || $month > 12) {
            return}}}