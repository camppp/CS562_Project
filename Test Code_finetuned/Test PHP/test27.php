public function parser( string $className, $objectAnnotation = null, string $propertyName, string $methodName, $propertyValue = null ): array {
    $result = [];

    // Check if the class exists
    if (!class_exists($className)) {
        return $result;
    }

    // Create a reflection class
    $reflectionClass = new ReflectionClass($className);

    // Check if the property exists in the class
    if ($reflectionClass->hasProperty($propertyName)) {
        // Get the property
        $property = $reflectionClass->getProperty($propertyName);

        // Check if the property value is provided
        if ($propertyValue!== null) {
            // Set the property value
            $property->setValue(new $className(), $propertyValue);
        }

        // Add the property value to the result
        $result['property'] = $property->getValue(new $className());
    }

    // Check if the method exists in the class
    if ($reflectionClass->hasMethod($methodName)) {
        // Get the method
        $method = $reflectionClass->getMethod($methodName);

        // Check if the method is public
        if ($method->isPublic()) {
            // Add the method result to the result
            $result['method'] = $method->invoke(new $className());
        }
    }

    // Check if the object annotation is provided
    if ($objectAnnotation!== null) {
        // Process the object annotation
        // This part is not implemented in this example
        // You need to implement this part based on your specific requirements
    }

    return $result;
}