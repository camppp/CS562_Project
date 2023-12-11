#!/bin/bash

# Set the JAVA_HOME environment variable
export JAVA_HOME=/home/daijin/.sdkman/candidates/java/11.0.1-open

# Use the Maven executable located at /usr/bin/mvn
mvn -Dexec.args=-classpath %classpath com.mycompany.jettytest.EmbeddedJettyMain -Dexec.executable=java -Dexec.classpathScope=runtime org.codehaus.mojo:exec-maven-plugin:1.5.0:exec

@echo off

:: Set the JAVA_HOME environment variable
set JAVA_HOME=C:\Program Files\Java\jdk-11.0.1

:: Use the Maven executable located at C:\Program Files\Apache Software Foundation\apache-maven-3.6.3\bin\mvn.bat
mvn -Dexec.args=-classpath %classpath com.mycompany