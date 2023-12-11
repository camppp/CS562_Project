function extractBaseUrls(array $filePaths): array
{
    $baseUrls = [];
    foreach ($filePaths as $filePath) {
        preg_match('/<?php echo (.*);?>/', $filePath, $matches);
        $baseUrl = $matches[1];
        if (!in_array($baseUrl, $baseUrls)) {
            $baseUrls[] = $baseUrl;
        }
    }
    return array_unique($baseUrls);
}