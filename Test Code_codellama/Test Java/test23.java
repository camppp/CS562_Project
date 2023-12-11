controlButton.setOnClickListener(new View.OnClickListener() {
    @Override
    public void onClick(View v) {
        count++;
        counterDisplay.setText(String.valueOf(count));
    }
});