import java.lang.annotation.*;

@Retention(RetentionPolicy.RUNTIME)
@Target({ElementType.CONSTRUCTOR})
@Inherited
public @interface ConstructorAnno {
    String value() default "default";
}

import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import javax.tools.*;
import java.io.*;
import java.util.*;

public class ConstructorAnnoProcessor extends AbstractProcessor {

    @Override
    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv) {
        for (Element element : roundEnv.getElementsAnnotatedWith(ConstructorAnno.class)) {
            if (element.getKind() == ElementKind.CONSTRUCTOR) {
                String className = ((TypeElement) element.getEnclosingElement()).getQualifiedName().toString();
                String constructorSignature = element.asType().toString();
                String value = element.getAnnotation(ConstructorAnno.class).value();
                System.out.println("Class: " + className + " Constructor: " + constructorSignature + ", Value: " + value);
            }
        }
        return true;
    }

    @Override
    public Set<String> getSupportedAnnotationTypes() {
        return new HashSet<>(Arrays.asList(ConstructorAnno.class.getCanonicalName()));
    }

    @Override
    public SourceVersion getSupportedSourceVersion() {
        return SourceVersion.latest();
    }
}

<build>
    <plugins>
        <plugin>
            <groupId>org.apache.maven.plugins</groupId>
            <artifactId>maven-compiler-plugin</artifactId>
            <version>3.8.1</version>
            <configuration>
                <source>1.8</source>
                <target>1.8</target>
                <annotationProcessorPaths>
                    <path>
                        <groupId>org.example</groupId>
                        <artifactId>my-processor</artifactId>
                        <version>1.0-SNAPSHOT</version>
                    </path>
                </annotationProcessorPaths>
            </configuration>
        </plugin>
    </plugins>
</build>