import java.util.function.Function;
import net.minecraft.nbt.CompoundNBT;

public class Instance {
    private String name;
    private int x;
    private int y;
    private int z;

    public Instance(String name, int x, int y, int z) {
        this.name = name;
        this.x = x;
        this.y = y;
        this.z = z;
    }

    // Getters and setters omitted for brevity
}

public class InstanceFunction implements Function<CompoundNBT, Instance> {
    @Override
    public Instance apply(CompoundNBT compoundNBT) {
        String name = compoundNBT.getString("name");
        CompoundNBT position = compoundNBT.getCompound("position");
        int x = position.getInt("x");
        int y = position.getInt("y");
        int z = position.getInt("z");
        return new Instance(name, x, y, z);
    }
}