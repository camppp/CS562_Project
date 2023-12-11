public class Session {
    private static final String SESSION_PREFS = "SessionPrefs";
    private static final String USER_ID_KEY = "userId";

    private Context context;
    private SharedPreferences sharedPreferences;

    public Session(Context context) {
        this.context = context;
        sharedPreferences = context.getSharedPreferences(SESSION_PREFS, Context.MODE_PRIVATE);
    }

