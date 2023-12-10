python
def extractModelNames(file_paths):
    model_names = []
    for path in file_paths:
        parts = path.split("/")
        file_name = parts[-1]
        model_name = file_name.split(".")[0]
        if "-" in model_name:
            model_name = model_name.split("-")[0]
        model_names.append(model_name)
    return model_names

def createSetModelAction(model_name):
    class ActionSetModel:
        def __init__(self, model_name):
            self.model_name = model_name

    return ActionSetModel(model_name)
