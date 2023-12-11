class BugReportRepository
{
    private $queryBuilder;

    public function __construct(QueryBuilder $queryBuilder)
    {
        $this->queryBuilder = $queryBuilder;
    }

    public function findAll(): array
    {
        $query = $this->queryBuilder
            ->select('*')
            ->from('bug_reports')
            ->getQuery();

        $bugReports = $query->execute()->fetchAll();

        return $bugReports;
    }
}