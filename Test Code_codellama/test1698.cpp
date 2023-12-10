void appendErrorMessage(StringBuilder& builder, unsigned int argumentIndex, const string& argumentName, const string& interfaceName, const string& functionName) {
    builder.append("Argument ");
    builder.append(to_string(argumentIndex));
    builder.append(": '");
    builder.append(argumentName);
    builder.append("' is invalid in ");
    builder.append(interfaceName);
    builder.append(".");
    builder.append(functionName);
    builder.append(".");
}
