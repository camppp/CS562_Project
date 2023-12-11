/**
 * @return void
 */
private function dispatchImportReconfigurationRequest(): void {
    try {
        // Define the file path
        $filePath = "input.txt";

        // Check if the file exists
        if (!file_exists($filePath)) {
            throw new Exception("File not found: $filePath");
        }

        // Read the file content
        $fileContent = file_get_contents($filePath);

        // Check if the file content is empty
        if (empty($fileContent)) {
            throw new Exception("File is empty: $filePath");
        }

        // Perform a simple transformation on the file content
        $transformedContent = strtoupper($fileContent);

        // Log the transformed content
        error_log("Transformed content: $transformedContent");

    } catch (Exception $e) {
        // Log any errors that occur during the process
        error_log("Error: ". $e->getMessage());
    }
}