import com.beust.jcommander.JCommander;
import com.beust.jcommander.Parameter;

public class VPNUserManager {

    @Parameter(names = {"-account", "-a"}, description = "Specifies the account for the VPN user", required = true)
    private String accountName;

    @Parameter(names = {"-project", "-p"}, description = "Specifies the project ID to which the VPN user will be added", required = true)
    private String projectId;

    @Parameter(names = {"-domain", "-d"}, description = "Specifies the domain ID for the VPN user", required = true)
    private String domainId;

    public static void main(String[] args) {
        VPNUserManager manager = new VPNUserManager();
        JCommander.newBuilder()
               .addObject(manager)
               .build()
               .parse(args);

        if (manager.accountName!= null && manager.domainId == null) {
            System.out.println("Error: Domain ID is required when specifying account name.");
            return;
        }

        System.out.println("Account Name: " + manager.accountName);
        System.out.println("Project ID: " + manager.projectId);
        System.out.println("Domain ID: " + manager.domainId);
    }
}