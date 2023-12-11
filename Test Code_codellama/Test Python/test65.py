class _resource:
    def get_info(self):
        raise NotImplementedError

class heroku_drain(_resource):
    def get_info(self):
        return "Heroku drain resource"

class heroku_pipeline(_resource):
    def get_info(self):
        return "Heroku pipeline resource"

class heroku_pipeline_coupling(_resource):
    def get_info(self):
        return "Heroku pipeline coupling resource"