@Override
public void onStartup(ServletContext servletContext) throws ServletException {
    // Register the HTTP facade with the URL pattern "/remoting/httpFacade"
    ServletRegistration.Dynamic httpFacadeServlet = servletContext.addServlet("httpFacade", new HttpFacadeServlet());
    httpFacadeServlet.addMapping("/remoting/httpFacade");

    // Register the SOAP dispatcher with a custom URL pattern "/soapDispatcher"
    ServletRegistration.Dynamic soapDispatcherServlet = servletContext.addServlet("soapDispatcher", new SoapDispatcherServlet());
    soapDispatcherServlet.addMapping("/soapDispatcher");
}