from rest_framework import permissions

class AnyGroupJWTBasePermission(permissions.BasePermission):
    """
    Custom permission to only allow authenticated users who belong to any group.
    """

    def has_permission(self, request, view):
        # Check if the user is authenticated
        if request.user and request.user.is_authenticated:
            # Check if the user belongs to any group
            if request.user.groups.exists():
                return True
        return False