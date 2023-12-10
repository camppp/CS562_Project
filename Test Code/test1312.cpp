void processMethodCall(int m_ciTemp, int m_objectTemp, int pcount) {
    // Extract the method call information from the temporary call info
    MethodCallInfo* m_ci = (MethodCallInfo*)m_ciTemp;
    Method* m = m_ci->method;
    Object* o = (Object*)m_objectTemp;

    // Print out the method call information
    printf("Method call: %s.%s(%d parameters)\n", m->name, o->name, pcount);

    // Construct the method call package
    MethodCallPackage* mcp = (MethodCallPackage*)malloc(sizeof(MethodCallPackage));
    mcp->method = m;
    mcp->object = o;
    mcp->parameters = (Parameter*)malloc(pcount * sizeof(Parameter));
    for (int i = 0; i < pcount; i++) {
        mcp->parameters[i] = m_ci->parameters[i];
    }
    mcp->parameterCount = pcount;

    // Add the method call package to the list of method call packages
    methodCallPackages.push_back(mcp);
}
