from django import forms
from django.core.exceptions import ValidationError

class FileAllowed:
    def __init__(self, allowed_formats):
        self.allowed_formats = allowed_formats

    def __call__(self, value):
        if not value.name.split('.')[-1] in self.allowed_formats:
            raise ValidationError(f'Wrong format! Allowed: {", ".join(self.allowed_formats)}')

class AvatarUploadForm(forms.Form):
    avatar = forms.FileField(validators=[FileAllowed(['jpg', 'png', 'gif'])])

    def clean_avatar(self):
        avatar = self.cleaned_data.get('avatar')
        if avatar:
            FileAllowed(['jpg', 'png', 'gif'])(avatar)
        return avatar