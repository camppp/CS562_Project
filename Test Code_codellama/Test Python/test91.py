def judge_command(command_str: str, expected_params: dict) -> bool:
    # Split the command string into its parts
    parts = command_str.split()

    # Check that the command is the expected one
    if parts[0] != expected_params["command"]:
        return False

    # Check that the key is the expected one
    if parts[1] != expected_params["key"]:
        return False

    # Check that the group is the expected one
    if parts[2] != expected_params["group"]:
        return False

    # Check that the stream ID range is the expected one
    if parts[3] != expected_params["stream_id"][0] or parts[4] != expected_params["stream_id"][1]:
        return False

    # Check that the count is the expected one
    if parts[5] != expected_params["count"]:
        return False

    # Check that the consumer is the expected one
    if parts[6] != expected_params["consumer"]:
        return False

    # If all checks passed, return True
    return True