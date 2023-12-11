function classAutoloader($className) {
    $classes = [
        'Symfony\Component\EventDispatcher\EventDispatcher' => 'EventDispatcher.php',
        'Symfony\Component\HttpKernel\EventListener\ErrorListener' => 'ErrorListener.php',
        'Symfony\Component\Filesystem\Filesystem' => 'Filesystem.php',
        'Symfony\Component\