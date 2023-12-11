import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.SequenceFile;
import org.apache.hadoop.io.Writable;

import java.io.IOException;

public class KeyValuePairCounter {

    public int countKeyValuePairs() throws IOException {
        Configuration conf = new Configuration();
        FileSystem fs = FileSystem.get(conf);
        Path path = new Path("/user/tri1/subgraph/line_fd/part-r-00000");

        SequenceFile.Reader reader = null;
        try {
            reader = new SequenceFile.Reader(fs, path, conf);
            Writable key = (Writable) reader.getKeyClass().newInstance();
            Writable value = (Writable) reader.getValueClass().newInstance();

            int count = 0;
            while (reader.next(key, value)) {
                count++;
            }

            return count;
        } finally {
            if (reader!= null) {
                reader.close();
            }
        }
    }
}