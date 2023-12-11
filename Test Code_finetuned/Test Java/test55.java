import com.ferreusveritas.dynamictrees.ModConfigs;
import com.ferreusveritas.dynamictrees.api.TreeHelper;

public int getTreeGrowthRate(String treeType) {
    // Get the tree configuration
    ModConfigs.TreeConfig treeConfig = ModConfigs.treeConfigs.get(treeType);

    // Get the growth rate from the tree configuration
    int growthRate = treeConfig.getGrowthRate();

    return growthRate;
}