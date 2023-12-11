import android.os.AsyncTask;
import android.util.Log;

public class SLApiTask extends AsyncTask<Void, Void, String> {

    @Override
    protected String doInBackground(Void... voids) {
        try {
            // Perform network operation here
            // For example, using SLApi library
            // String data = SLApi.fetchData();
            // return data;
        } catch (SLApiException e) {
            // Handle the exception
            Log.e("SLApiException", e.getMessage());
            return e.getMessage();
        }
        return null;
    }

    @Override
    protected void onPostExecute(String result) {
        if (result!= null) {
            // Display the result
            Log.d("Result", result);
        } else {
            // Handle the exception
            Log.e("SLApiException", "An error occurred while fetching data");
        }
    }
}