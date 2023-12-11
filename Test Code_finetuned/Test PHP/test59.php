public function getI18nAttributes($languageCode) {
    $i18nAttributes = array();

    foreach ($this->i18n as $attribute) {
        if (isset($this->$attribute[$languageCode])) {
            $i18nAttributes[$attribute] = $this->$attribute[$languageCode];
        }
    }

    return $i18nAttributes;
}

public $attributes = array(
    'name' => array(
        'en' => 'Name',
        'fr' => 'Nom',
        'es' => 'Nombre'
    ),
    'description' => array(
        'en' => 'Description',
        'fr' => 'Description',
        'es' => 'Descripción'
    ),
    'pjActionRequired' => true
);