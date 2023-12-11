from rest_framework import permissions

class AnyGroupJWTBasePermission(permissions.BasePermission):
    def has_permission(self, request, view):
        # Check if the user is authenticated
        if not request.user.is_authenticated:
            return False

        # Check if the user belongs to any group
        if request.user.groups.exists():
            return True

        # If the user is not authenticated or does not belong to any group, deny access
        return False