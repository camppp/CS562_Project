import java.util.Collections;
import java.util.List;

public class TrainingManager {
    private double learningRate_;
    private Configuration config_;
    private List<Object> trainingSet; // Assume trainingSet is a list of objects

    public TrainingManager(double initialLearningRate, Configuration config, List<Object> trainingSet) {
        this.learningRate_ = initialLearningRate;
        this.config_ = config;
        this.trainingSet = trainingSet;
    }

    public void updateLearningRate() {
        if (config_.decayRate < 1.0) {
            learningRate_ *= config_.decayRate;
        }
    }

    public void shuffle() {
        if (config_.shuffleTrainingSet) {
            Collections.shuffle(trainingSet);
            System.out.println("Training dataset shuffled.");
        }
    }

    // Other methods and attributes can be added as per the requirements
}

class Configuration {
    double decayRate;
    boolean shuffleTrainingSet;

    public Configuration(double decayRate, boolean shuffleTrainingSet) {
        this.decayRate = decayRate;
        this.shuffleTrainingSet = shuffleTrainingSet;
    }
}