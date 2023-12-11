from django.contrib import admin
from django.contrib.auth.models import User

class UserAdmin(admin.ModelAdmin):
    list_display = ('username', 'email', 'first_name', 'last_name', 'is_staff')
    list_filter = ('is_staff', 'is_superuser', 'groups')
    search_fields = ('username', 'email', 'first_name', 'last_name')
    ordering = ('username', 'email', 'first_name', 'last_name')
    inlines = (UserProfileInline,)

    def name(self, user):
        return f"{user.first_name} {user.last_name}"

class UserProfileInline(admin.StackedInline):
    model = UserProfile
    can_delete = False
    verbose_name_plural = 'user profiles'

class UserProfile(models.Model):
    user = models.OneToOneField(User, on_delete=models.CASCA)