java
import java.io.FileOutputStream;
import java.io.IOException;

public class BinFileOutputStream {
    private String fileName;
    private FileOutputStream fileOutputStream;
    private int bytesWritten;

    public void openFile(String filename) {
        try {
            fileOutputStream = new FileOutputStream(filename);
            fileName = filename;
        } catch (IOException e) {
            System.out.println("Error opening the file: " + e.getMessage());
        }
    }

    public void writeInt(int value) {
        try {
            fileOutputStream.write(value);
            bytesWritten += Integer.BYTES;
        } catch (IOException e) {
            System.out.println("Error writing integer to file: " + e.getMessage());
        }
    }

    public void writeDouble(double value) {
        try {
            long longValue = Double.doubleToRawLongBits(value);
            fileOutputStream.write((int) (longValue & 0xFF));
            fileOutputStream.write((int) ((longValue >> 8) & 0xFF));
            fileOutputStream.write((int) ((longValue >> 16) & 0xFF));
            fileOutputStream.write((int) ((longValue >> 24) & 0xFF));
            fileOutputStream.write((int) ((longValue >> 32) & 0xFF));
            fileOutputStream.write((int) ((longValue >> 40) & 0xFF));
            fileOutputStream.write((int) ((longValue >> 48) & 0xFF));
            fileOutputStream.write((int) ((longValue >> 56) & 0xFF));
            bytesWritten += Double.BYTES;
        } catch (IOException e) {
            System.out.println("Error writing double to file: " + e.getMessage());
        }
    }

    public void writeString(String value) {
        try {
            byte[] bytes = value.getBytes();
            fileOutputStream.write(bytes);
            bytesWritten += bytes.length;
        } catch (IOException e) {
            System.out.println("Error writing string to file: " + e.getMessage());
        }
    }

    public void closeFile() {
        try {
            fileOutputStream.close();
        } catch (IOException e) {
            System.out.println("Error closing the file: " + e.getMessage());
        }
    }

    public String getFileName() {
        return fileName;
    }

    public int getBytesWritten() {
        return bytesWritten;
    }
}
