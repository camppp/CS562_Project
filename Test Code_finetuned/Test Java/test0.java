public class User {
    private String role;
    // other attributes

    // getters and setters
}

public class Permission {
    private String value;
    // other attributes

    // getters and setters
}

public class PermissionChecker {
    public boolean checkPermission(User user, Permission permission) {
        // Assuming that the user's role is stored in a list of roles
        List<String> userRoles = getUserRoles(user);

        // Assuming that the permission's value is stored in a list of permissions
        List<String> userPermissions = getUserPermissions(userRoles);

        // Check if the user has the required permission
        return userPermissions.contains(permission.getValue());
    }

    private List<String> getUserRoles(User user) {
        // Implement logic to retrieve user roles
        // This could be a database query or a service call
        return null;
    }

    private List<String> getUserPermissions(List<String> userRoles) {
        // Implement logic to retrieve user permissions
        // This could be a database query or a service call
        return null;
    }
}