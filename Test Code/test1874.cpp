bool IsKeyDown(GT::Script script)
{
    // Get the key to be checked from the script's first parameter
    Key key = (Key)script.ToInteger(1);

    // Get the context object for the script
    auto context = script.GetContext();

    // Check if the key is currently pressed
    return context.IsKeyDown(key);
}
