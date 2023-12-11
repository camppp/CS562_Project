function generateUserDetails($startingPhoneNumber, $count, $userAddressTypes) {
    $userDetails = [];
    for ($i = 0; $i < $count; $i++) {
        $userAddress = [
            'country' => $this->faker->country,
            'type' => $this->faker->randomElement($userAddressTypes),
        ];
        $userCustomPhone = generateUniquePhoneNumber($startingPhoneNumber, $i);
        $user = new User();
        $user->setAddress($userAddress);
        $user->setCustomPhone($userCustomPhone);
        $userDetails[] = [
            'address' => $userAddress,
            'phone' => $userCustomPhone,
        ];
    }
    return $userDetails;
}

function generateUniquePhoneNumber($startingPhoneNumber, $count) {