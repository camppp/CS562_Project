public boolean checkPermission(String userRole, String requiredPermission) {
  // Retrieve the user's permissions
  List<String> userPermissions = getUserPermissions(userRole);

  // Check if the user has the required permission
  return userPermissions.contains(requiredPermission);
}