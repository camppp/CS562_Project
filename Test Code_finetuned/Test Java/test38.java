@Nullable
@Override
public String getType(@NonNull Uri uri) {
    int match = mUriMatcher.match(uri);
    switch (match) {
        case MATCHES:
            return ProviderHelper.CONTENT_TYPE_ENTRIES;
        default:
            throw new UnsupportedOperationException("Unknown uri :" + uri);
    }
}