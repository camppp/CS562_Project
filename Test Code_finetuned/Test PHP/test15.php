function generateCssUrl(environment) {
    if (environment === 'development') {
        return '/css/app.css';
    } else if (environment === 'production') {
        return '/static/css/app.css';
    } else {
        throw new Error('Invalid environment. It should be either "development" or "production".');
    }
}