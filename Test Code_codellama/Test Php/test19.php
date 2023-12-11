use Doctrine\ORM\EntityRepository;
use Doctrine\ORM\QueryBuilder;

class UserRepository extends EntityRepository
{
    public function findUsersByRegistrationDateRange(DateTime $startDate, DateTime $endDate): array
    {
        $qb = $this->createQueryBuilder('u');
        $qb->where('u.registrationDate >= :startDate')
           ->andWhere('u.registrationDate <= :endDate')
           ->setParameter('startDate', $startDate)
           ->setParameter('endDate', $endDate);

        return $qb->getQuery()->getResult();
    }
}