public function get_angka() {
    $varkode = $this->input->get('varkode');
    switch($varkode) {
        case 1:
            $varkode = 'ADM';
            break;
        case 2:
            $varkode = 'USR';
            break;
        case 3:
            $varkode = 'MOD';
            break;
        case 4:
            $varkode = 'GUE';
            break;
        case 5:
            $varkode = 'OTH';
            break;
        default:
            $varkode = 'NA';
            break;
    }
    return $varkode;
}