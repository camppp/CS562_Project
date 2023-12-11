function test_divmail() {
    global $driver, $base_url, $divmail_url;

    // Login
    $driver->get($base_url);
    $driver->findElement(WebDriverBy::id('username'))->sendKeys('admin');
    $driver->findElement(WebDriverBy::id('password'))->sendKeys('adm1n');
    $driver->findElement(WebDriverBy::id('login'))->click();

    // Navigate to divmail page
    $driver->get($divmail_url);

    // Capture screenshot
    take_pageshot();

    // Logout
    $driver->findElement(WebDriverBy::id('logout'))->click();
}