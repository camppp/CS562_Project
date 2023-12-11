public class Session {
    private static final String SESSION_PREFS = "SessionPrefs";
    private static final String USER_ID_KEY = "userId";
    private Context context;
    private SharedPreferences sharedPreferences;
    private FirebaseAuth firebaseAuth;

    public Session(Context context) {
        this.context = context;
        sharedPreferences = context.getSharedPreferences(SESSION_PREFS, Context.MODE_PRIVATE);
        firebaseAuth = FirebaseAuth.getInstance();
    }

    public void startSession(String userId) {
        SharedPreferences.Editor editor = sharedPreferences.edit();
        editor.putString(USER_ID_KEY, userId);
        editor.apply();

        // Authenticate user using Firebase
        firebaseAuth.signInWithEmailAndPassword(userId, "password"); // Assuming password is hardcoded
    }

    public void endSession() {
        SharedPreferences.Editor editor = sharedPreferences.edit();
        editor.remove(USER_ID_KEY);
        editor.apply();

        // Sign out user from Firebase
        firebaseAuth.signOut();
    }

    public boolean isSessionActive() {
        String userId = sharedPreferences.getString(USER_ID_KEY, null);

        // Check if user is authenticated with Firebase
        FirebaseUser currentUser = firebaseAuth.getCurrentUser();
        return userId!= null && currentUser!= null;
    }
}