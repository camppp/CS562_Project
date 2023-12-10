void argon::vm::ContextDel(Context *context) {
    if (context == nullptr) {
        // Handle the case where the context pointer is already null
        return;
    }

    // Release any resources associated with the context
    // For example, release any values stored in the context's namespace
    // Assuming a function ReleaseNamespaceValues exists to release all values in a namespace
    ReleaseNamespaceValues(context->runtime->module_ns);

    // Release the context itself
    Release(context);
}
