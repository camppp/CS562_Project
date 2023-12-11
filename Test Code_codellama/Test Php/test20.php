use Doctrine\ORM\EntityManagerInterface;
use App\Entity\Currency;
use App\Entity\Rate;

function generateAndStoreExchangeRates(array $currencyCodes): void
{
    $em = $this->getDoctrine()->getManager();

    foreach ($currencyCodes as $currencyCode) {
        $currency = $em->getRepository(Currency::class)->findOneBy(['code' => $currencyCode]);

        if (!$currency) {
            throw new \Exception(sprintf('Currency with code "%s" not found', $currencyCode));
        }

        $rate = new Rate();
        $rate->setCurrencyId($currency->getId());
        $rate->setRateValue(mt_rand(0.5, 2));
        $rate->setCreatedAt(new \DateTime());

        $em->persist($rate);
    }

    $em->flush();
}