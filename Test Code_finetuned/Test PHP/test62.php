def delete_role(role_id: int) -> str:
    roles = {1: "Admin", 2: "User", 3: "Manager"}
    if role_id in roles:
        del roles[role_id]
        return f"Role with ID {role_id} has been successfully deleted."
    else:
        return f"Role with ID {role_id} does not exist."