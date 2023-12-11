function generateUserReport(array $users): array
{
    $report = [];

    foreach ($users as $user) {
        $apiAuth = ApiAuth::find($user->id);

        if ($apiAuth) {
            $report[] = [
                'id' => $user->id,
                'Username' => $user->email,
                'ClientKey' => $apiAuth->client_key,
                'ClientSecret' => $apiAuth->client_secret,
                'ApiKey' => $apiAuth->api_key,
            ];
        } else {
            $report[] = [
                'id' => $user->id,
                'Username' => $user->email,
                'ClientKey' => '',
                'ClientSecret' => '',
                'ApiKey' => '',
            ];
        }
    }

    return $report;
}