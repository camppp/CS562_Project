function generateKeyboardJSON(array $k, bool $rk, bool $otk, bool $s): string
{
    $json = [
        'keyboard' => $k,
        'resize_keyboard' => $rk,
        'one_time_keyboard' => $otk,
        'selective' => $s
    ];

    return json_encode($json, JSON_PRETTY_PRINT);
}
