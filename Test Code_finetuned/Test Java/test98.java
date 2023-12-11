import java.io.IOException;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

import ch.skymarshall.tcwriter.generators.model.persistence.IModelPersister;
import ch.skymarshall.tcwriter.generators.model.persistence.JsonModelPersister;
import ch.skymarshall.tcwriter.generators.model.testapi.TestDictionary;
import ch.skymarshall.tcwriter.generators.visitors.ClassToDictionaryVisitor;
import ch.skymarshall.util.helpers.ClassFinder;

public class JavaToDictionary {
    private final Collection<Class<?>> tcClasses;

    public JavaToDictionary(Collection<Class<?>> tcClasses) {
        this.tcClasses = tcClasses;
    }

    public void convertToDictionary() {
        Map<String, TestDictionary> dictionary = new HashMap<>();
        ClassToDictionaryVisitor visitor = new ClassToDictionaryVisitor();

        for (Class<?> tcClass : tcClasses) {
            try {
                TestDictionary testDictionary = visitor.visit(tcClass);
                dictionary.put(tcClass.getName(), testDictionary);
            } catch (Exception e) {
                System.out.println("Error converting class " + tcClass.getName() + " to dictionary: " + e.getMessage());
            }
        }

        IModelPersister persister = new JsonModelPersister();
        try {
            persister.persist(dictionary);
        } catch (IOException e) {
            System.out.println("Error persisting dictionary: " + e.getMessage());
        }
    }
}