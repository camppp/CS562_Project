void processFetchedURLs() {
    if (!gVectTodoPathJA.empty()) {
        auto top = gVectTodoPathJA.back();
        gVectTodoPathJA.pop_back();
        gFetchServer->send(top);
    } else {
        gFetchServer->send("");
    }
}
