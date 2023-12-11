import java.math.BigDecimal;

public class ApplicationResourceBuilder {
    private BigDecimal totalCompletion;

    //... other methods and fields

    public ApplicationResourceBuilder withCompletion(final BigDecimal... bigDecimals) {
        if (bigDecimals == null || bigDecimals.length == 0) {
            this.totalCompletion = BigDecimal.ZERO;
        } else {
            this.totalCompletion = BigDecimal.ZERO;
            for (BigDecimal bigDecimal : bigDecimals) {
                this.totalCompletion = this.totalCompletion.add(bigDecimal);
            }
        }
        return this;
    }

    //... other methods
}