public function parser(string $className, $objectAnnotation = null, string $propertyName, string $methodName, $propertyValue = null): array
{
    $result = [];

    if ($objectAnnotation) {
        // Parse the object annotation and extract the relevant information
        $annotation = $this->parseObjectAnnotation($objectAnnotation);
        $result['annotation'] = $annotation;
    }

    // Process the property name and method name
    $result['propertyName'] = $propertyName;
    $result['methodName'] = $methodName;

    // Process the property value
    if ($propertyValue) {
        $result['propertyValue'] = $propertyValue;
    }

    return $result;
}

private function parseObjectAnnotation($objectAnnotation): array
{
    // Parse the object annotation and extract the relevant information
    // This function should return an array containing the relevant information
    // about the object annotation, such as the class name, the property name,
    // and the method name.
}