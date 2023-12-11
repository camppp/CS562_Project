@Override
public void onStartup(ServletContext servletContext) throws ServletException {
    // Create the 'root' Spring application context
    AnnotationConfigWebApplicationContext rootContext = new AnnotationConfigWebApplicationContext();
    rootContext.register(AppConfig.class);

    // Manage the lifecycle of the root application context
    servletContext.addListener(new ContextLoaderListener(rootContext));

    // Create the dispatcher servlet's Spring application context
    AnnotationConfigWebApplicationContext dispatcherContext = new AnnotationConfigWebApplicationContext();
    dispatcherContext.register(DispatcherConfig.class);

    // Register and map the dispatcher servlet
    ServletRegistration.Dynamic dispatcher = servletContext.addServlet("dispatcher", new DispatcherServlet(dispatcherContext));
    dispatcher.setLoadOnStartup(1);
    dispatcher.addMapping("/");

    // Register the HTTP facade
    HttpFacade httpFacade = new HttpFacade();
    servletContext.addServlet("httpFacade", new HttpFacadeServlet(httpFacade)).addMapping("/remoting/httpFacade");

    // Register the SOAP dispatcher
    SoapDispatcher soapDispatcher = new SoapDispatcher();
    servletContext.addServlet("soapDispatcher", new SoapDispatcherServlet(soapDispatcher)).addMapping("/soapDispatcher");
}