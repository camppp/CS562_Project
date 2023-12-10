int FireStepSerial::executeCore(const std::string &request, std::string &response)
{
    // Check if the request is "status"
    if (request == "status")
    {
        response = "System is operational";
        return 0;
    }

    // Check if the request is "move up"
    else if (request == "move up")
    {
        response = "Moving up";
        return 0;
    }

    // Check if the request is "move down"
    else if (request == "move down")
    {
        response = "Moving down";
        return 0;
    }

    // Check if the request is "stop"
    else if (request == "stop")
    {
        response = "Stopping movement";
        return 0;
    }

    // Check if the request is "reset"
    else if (request == "reset")
    {
        response = "Resetting system";
        return 0;
    }

    // If the request does not match any of the above commands, set the response to "Invalid command"
    else
    {
        response = "Invalid command";
        return 1;
    }
}
