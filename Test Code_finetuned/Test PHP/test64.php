class BugReportRepository
{
    private $queryBuilder;

    public function __construct(QueryBuilder $queryBuilder)
    {
        $this->queryBuilder = $queryBuilder;
    }

    public function findAll(): array
    {
        $this->queryBuilder->select('*')->from('bug_reports');
        $bugReportsData = $this->queryBuilder->execute();

        $bugReports = [];
        foreach ($bugReportsData as $bugReportData) {
            $bugReports[] = new BugReport($bugReportData);
        }

        return $bugReports;
    }
}