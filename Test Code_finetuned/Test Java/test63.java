import com.google.gson.annotations.SerializedName;

public class InputParameters {
    @SerializedName("Part_Key")
    private int partKey;

    public InputParameters(int partKey) {
        this.partKey = partKey;
    }

    public int getPartKey() {
        return partKey;
    }
}