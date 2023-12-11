public class MainActivity extends AppCompatActivity {
    private Button controlButton;
    private TextView counterDisplay;
    private int count = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        controlButton = findViewById(R.id.controlButton);
        counterDisplay = findViewById(R.id.counterDisplay);

        controlButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                count++;
                counterDisplay.setText(String.valueOf(count));
            }
        });
    }
}