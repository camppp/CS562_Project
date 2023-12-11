function test_divmail() {
  // Log in to the web application
  $driver = new RemoteWebDriver('http://localhost:4444/wd/hub', DesiredCapabilities::chrome());
  $driver->get($base_url);
  $driver->findElement(WebDriverBy::id('username'))->sendKeys('admin');
  $driver->findElement(WebDriverBy::id('password'))->sendKeys('adm1n');
  $driver->findElement(WebDriverBy::name('login'))->click();

  // Navigate to the "divmail" page
  $driver->get($divmail_url);

  // Capture a screenshot of the "divmail" page
  $screenshot = $driver->take_pageshot();

  // Log out from the web application
  $driver->findElement(WebDriverBy::linkText('Logout'))->click();
  $driver->quit();

  // Assert that the screenshot was captured