from django.shortcuts import render
from.models import Plugin

def Apps(request):
    # Retrieve a list of installed plugins from the database
    installed_plugins = Plugin.objects.filter(installed=True)

    # Prepare the data to be passed to the template
    context = {
        'plugins': installed_plugins,
    }

    # Render the list of plugins in a web page using a template
    return render(request, 'plugins.html', context)