java
public class Solution {
    public void populateRimap(Long[] Sj, Double[] Sx, int i, int fn, cpuElement[] cpuS) {
        // Populate cpuS data structure
        int sindex = 0;
        for (int p = 0; p < Sj.length; p++) {
            Long j = Sj[p];
            cpuS[sindex].findex = i * fn + j;
            cpuS[sindex].value = Sx[p];
            sindex++;
        }

        // Build Rimap data structure
        // Assuming Rimap is a Map<Long, Double>
        Map<Long, Double> Rimap = new HashMap<>();
        for (cpuElement element : cpuS) {
            Rimap.put(element.findex, element.value);
        }
        // Use Rimap as needed
    }
}
