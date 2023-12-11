import android.app.Activity;
import android.os.Bundle;
import android.view.GestureDetector;
import android.view.MotionEvent;

public class GestureDetectorActivity extends Activity {
    private GestureDetector gestureDetector;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        gestureDetector = new GestureDetector(this, new GestureListener());
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        return gestureDetector.onTouchEvent(event);
    }

    private class GestureListener extends GestureDetector.SimpleOnGestureListener {
        @Override
        public boolean onDoubleTap(MotionEvent e) {
            // Perform the desired action when the double tap is recognized
            // For example, you could trigger a toast message or start a new activity
            Toast.makeText(getApplicationContext(), "Double tap recognized", Toast.LENGTH_SHORT).show();
            return true;
        }
    }
}