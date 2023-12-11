import java.net.URI;

public class OntologyEntity {
    private String label;
    private URI ontologyId;

    // Add a constructor to set the label of the entity
    public OntologyEntity(String label) {
        this.label = label;
    }

    // Add a method to retrieve the ontology ID associated with the entity
    public URI getOntologyId() {
        return this.ontologyId;
    }

    // Set the ontology ID associated with the entity
    public void setOntologyId(URI ontologyId) {
        this.ontologyId = ontologyId;
    }
}