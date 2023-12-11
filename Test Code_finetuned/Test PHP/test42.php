function generateUserDetails($startingPhoneNumber, $count, $userAddressTypes) {
    $faker = Faker\Factory::create();
    $userDetails = [];

    for ($i = 0; $i < $count; $i++) {
        $userDetails[] = [
            "address" => [
                "country" => $faker->country,
                "type" => $faker->randomElement($userAddressTypes)
            ],
            "phone" => $startingPhoneNumber + $i
        ];
    }

    return $userDetails;
}