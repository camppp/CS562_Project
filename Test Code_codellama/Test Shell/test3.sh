import re

def parse_ros_environment(code_snippet: str) -> dict:
    """
    Parses the input string and extracts the ROS_MASTER_URI and ROS_IP values.

    Args:
        code_snippet (str): The input string containing the ROS environment setup commands.

    Returns:
        dict: A dictionary containing the ROS_MASTER_URI and ROS_IP values.
    """
    # Use regular expressions to extract the ROS_MASTER_URI and ROS_IP values
    pattern = r"export ROS_MASTER_URI=(.*)"
    match = re.search(pattern, code_snippet)
    if match:
        ros_master_uri = match.group(1)
    else:
        raise ValueError("ROS_MAST")