public function getI18nAttributes($languageCode)
{
    // Check if the provided language code is supported
    if (!in_array($languageCode, array_keys($this->i18n))) {
        return array();
    }

    // Retrieve the internationalized attributes for the specified language
    $i18nAttributes = array();
    foreach ($this->i18n[$languageCode] as $key => $value) {
        $i18nAttributes[$key] = $this->attributes[$key];
    }

    return $i18nAttributes;
}