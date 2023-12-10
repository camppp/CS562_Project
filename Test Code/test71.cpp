java
public class TrainingManager {
    private double learningRate_;
    private Configuration config_;

    public TrainingManager(double initialLearningRate, Configuration config) {
        this.learningRate_ = initialLearningRate;
        this.config_ = config;
    }

    public void updateLearningRate() {
        if (config_.decayRate < 1.0) {
            learningRate_ *= config_.decayRate;
        }
    }

    public void shuffle() {
        if (config_.shuffleTrainingSet) {
            // Implement dataset shuffling logic here
            // ...
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
