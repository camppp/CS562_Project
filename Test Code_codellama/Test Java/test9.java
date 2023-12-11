import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.SequenceFile;
import org.apache.hadoop.io.Text;

public class KeyValueCounter {
  private Configuration conf;
  private FileSystem fs;
  private Path filePath;
  private SequenceFile.Reader reader;

  public KeyValueCounter(String filePath) throws IOException {
    this.conf = new Configuration();
    this.fs = FileSystem.get(conf);
    this.filePath = new Path(filePath);
    this.reader = new SequenceFile.Reader(fs, filePath, conf);
  }

  public int countKeyValuePairs() throws IOException {
    int count = 0;
    while (reader.next(new Text(), new Text())) {
      count++;
    }
    return count;
  }
}