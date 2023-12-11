#!/bin/bash

# Set JAVA_HOME
export JAVA_HOME=/home/daijin/.sdkman/candidates/java/11.0.1-open

# Set MAVEN_HOME
MAVEN_HOME=/usr/bin/mvn

# Execute Maven with the specified arguments
$MAVEN_HOME -Dexec.args="-classpath %classpath com.mycompany.jettytest.EmbeddedJettyMain" -Dexec.executable=java -Dexec.classpathScope=runtime org.codehaus.mojo:exec-maven-plugin:1.5.0:exec