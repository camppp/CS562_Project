<thead>
<tbody>
<?php foreach ($detail_data as $detail) :?>
    <tr>
        <td><?= $no++;?></td>
        <td><?= $detail['pernyataan_risiko'];?></td>
        <?php $jml_skor_risiko = 0; foreach ($detail['skor_risiko'] as $r) { 
            echo '<td class="text-center">'. $r. '</td>'; 
            $jml_skor_risiko = $jml_skor_risiko + $r; 
        }?>
        <td class="text-center"><b><?= $jml_skor_risiko;?></b></td>
    </tr>
<?php endforeach;?>