python
def DirectivesUpdated(directives):
    actions = {
        "update": "updated",
        "delete": "deleted",
        "create": "created"
    }
    executed_actions = []
    for directive in directives:
        action, target = directive.split(":")
        if action in actions:
            executed_actions.append(f"{target.capitalize()} {actions[action]}")
        else:
            executed_actions.append("Invalid directive")
    return executed_actions
