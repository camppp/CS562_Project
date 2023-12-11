<?php
foreach ($detail_data as $detail) {
    $jml_skor_risiko = 0;
    foreach ($detail['skor_risiko'] as $r) {
        $jml_skor_risiko = $jml_skor_risiko + $r;
    }
    echo '<td class="text-center">' . $jml_skor_risiko . '</td>';
}
?>