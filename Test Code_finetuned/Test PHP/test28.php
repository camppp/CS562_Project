function classAutoloader($className) : string {
    $classes = [
        'Symfony\Component\EventDispatcher\EventDispatcher',
        'Symfony\Component\HttpKernel\EventListener\ErrorListener',
        'Symfony\Component\Filesystem\Filesystem',
        'Symfony\Component\HttpKernel\HttpKernel',
        'Symfony\Component\HttpKernel\Controller\TraceableControllerResolver',
        'Symfony\Bundle\FrameworkBundle\Controller\ControllerResolver'
    ];

    if (in_array($className, $classes)) {
        $filePath = str_replace('\\', '/', $className). '.php';
        return $filePath;
    } else {
        return "Class not found";
    }
}

echo classAutoloader('Symfony\Component\Filesystem\Filesystem'); // Output: 'Symfony/Component/Filesystem/Filesystem.php'