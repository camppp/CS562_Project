java
import java.util.concurrent.TimeUnit;
import java.util.stream.Stream;

public class DelayedStreamPipeline {
    private Stream delayedStream;

    public DelayedStreamPipeline addDelayedStream(Stream source, long delay) {
        delayedStream = source.map(element -> {
            try {
                TimeUnit.MILLISECONDS.sleep(delay);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            return element;
        });
        return this;
    }
}
