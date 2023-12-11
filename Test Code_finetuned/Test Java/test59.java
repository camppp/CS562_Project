import java.util.ArrayList;

public class CertificateManager {
    private ArrayList<String> certificateList;

    public CertificateManager() {
        certificateList = new ArrayList<>();
    }

    public void addCertificate(String certificate) {
        certificateList.add(certificate);
    }

    public String[] getAllCertificates() {
        return certificateList.toArray(new String[0]);
    }
}