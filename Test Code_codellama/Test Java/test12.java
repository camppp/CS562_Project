import com.fasterxml.jackson.annotation.JsonProperty;
import com.fasterxml.jackson.databind.annotation.JsonSerialize;

@Data
@EqualsAndHashCode(callSuper = true)
public class CurrencyResponse extends JSONResponse {
    @JsonProperty("Currency")
    @JsonSerialize(using = DoubleSerializer.class)
    private double convertedCurrency;

    public CurrencyResponse(double convertedCurrency) {
        this.convertedCurrency = convertedCurrency;
    }
}