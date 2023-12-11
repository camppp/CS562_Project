function generateAndStoreExchangeRates(array $currencyCodes): void {
    $doctrine = $this->getDoctrine();
    $em = $doctrine->getManager();

    foreach ($currencyCodes as $currencyCode) {
        $currency = $em->getRepository(Currencies::class)->findOneBy(['code' => $currencyCode]);

        if (!$currency) {
            throw new \Exception("Currency with code $currencyCode not found");
        }

        $rate = new Rates();
        $rate->setRateValue(mt_rand(1, 10000) / 100);
        $rate->setCurrencyId($currency);
        $rate->setCreatedAt(new \DateTime());

        $em->persist($rate);
    }

    $em->flush();
}