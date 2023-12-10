bool IsKeyDown(GT::Script &script, Key key) {
    script.Push(GetContext(script).IsKeyDown(static_cast<Key>(key)));
    return script.ToBool(-1);
}
