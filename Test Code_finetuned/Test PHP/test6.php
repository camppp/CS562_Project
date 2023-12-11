function handleNewsletterRegistration(data, that) {
    // Disable the newsletter registration button
    document.getElementById('newsletter-register-button').disabled = true;

    // Send a POST request to the route
    fetch('{{route('email.register')}}', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify(data),
    })
   .then(response => response.json())
   .then(data => {
        // Enable the newsletter registration button
        document.getElementById('newsletter-register-button').disabled = false;

        // Get the newsletter message element
        let newsletterMessage = document.querySelector('.newsletter-message');

        // Remove any existing message
        newsletterMessage.innerHTML = '';

        // Display the appropriate message
        if (data.status === 'err') {
            newsletterMessage.style.color ='red';
            newsletterMessage.innerHTML = data.message;
        } else {
            newsletterMessage.style.color = 'green';
            newsletterMessage.innerHTML = data.message;
        }
    })
   .catch(error => {
        // Enable the newsletter registration button
        document.getElementById('newsletter-register-button').disabled = false;

        // Display an error message
        let newsletterMessage = document.querySelector('.newsletter-message');
        newsletterMessage.style.color ='red';
        newsletterMessage.innerHTML = 'An error occurred while registering for the newsletter. Please try again later.';
    });
}