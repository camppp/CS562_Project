public class SPQRNodeMetricsConfiguration {
    private int spqrMetric1;
    private int spqrMetric2;
    private int spqrMetric3;

    public SPQRNodeMetricsConfiguration(int spqrMetric1, int spqrMetric2, int spqrMetric3) {
        this.spqrMetric1 = spqrMetric1;
        this.spqrMetric2 = spqrMetric2;
        this.spqrMetric3 = spqrMetric3;
    }

    public int getSpqrMetric1() {
        return spqrMetric1;
    }

    public int getSpqrMetric2() {
        return spqrMetric2;
    }

    public int getSpqrMetric3() {
        return spqrMetric3;
    }
}

public class GraphNode {
    private SPQRNodeMetricsConfiguration spqrMetrics;

    public void setSpqrMetrics(SPQRNodeMetricsConfiguration spqrMetrics) {
        this.spqrMetrics = spqrMetrics;
    }

    public SPQRNodeMetricsConfiguration getSpqrMetrics() {
        return spqrMetrics;
    }
}