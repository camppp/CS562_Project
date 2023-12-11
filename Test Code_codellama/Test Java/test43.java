@Entity
@Table(name = "main_entity")
public class MainEntity {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @OneToOne(mappedBy = "mainEntity")
    private RelatedEntity relatedEntity;

    // getters and setters
}

@Entity
@Table(name = "related_entity")
public class RelatedEntity {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @OneToOne
    @JoinColumn(name = "main_entity_id")
    private MainEntity mainEntity;

    // getters and setters
}
```
2. Define the repository interfaces:
```
public interface MainEntityRepository extends JpaRepository<MainEntity, Long> {

    @Query("SELECT m FROM MainEntity m WHERE m.id = :id")
    Optional<MainEntity> findById(@Param("id") Long id);

    @Query("SELECT m FROM MainEntity m WHERE m.relatedEntity.id = :relatedEntityId")
    Optional<MainEntity> findByRelatedEntityId(@Param("relatedEntityId") Long relatedEntityId);
}

public interface RelatedEntityRepository extends JpaRepository<RelatedEntity, Long> {

    @Query("SELECT r FROM RelatedEntity r WHERE r.mainEntity.id = :mainEntityId")
    Optional<RelatedEntity> findByMainEntityId(@Param("mainEntityId") Long mainEntityId);
}
```
3. Implement the service methods:
```
@Service
public class MainEntityService {

    @Autowired
    private MainEntityRepository mainEntityRepository;

    @Autowired
    private RelatedEntityRepository relatedEntityRepository;

    public MainEntity createMainEntity(String name, String description) {
        MainEntity mainEntity = new MainEntity();
        mainEntity.setName(name);
        mainEntity.setDescription(description);

        RelatedEntity relatedEntity = new RelatedEntity();
        relatedEntity.setMainEntity(mainEntity);

        mainEntityRepository.save(mainEntity);
        relatedEntityRepository.save(relatedEntity);

        return mainEntity;
    }

    public Optional<MainEntity> getMainEntityById(Long id) {
        return mainEntityRepository.findById(id);
    }

    public void updateMainEntity(Long id, String name, String description) {
        MainEntity mainEntity = mainEntityRepository.findById(id).orElseThrow(() -> new ResourceNotFoundException("MainEntity not found with id " + id));
        mainEntity.setName(name);
        mainEntity.setDescription(description);
        mainEntityRepository.save(mainEntity);
    }

    public void deleteMainEntity(Long id) {
        MainEntity mainEntity = mainEntityRepository.findById(id).orElseThrow(() -> new ResourceNotFoundException("MainEntity not found with id " + id));
        relatedEntityRepository.deleteByMainEntityId(mainEntity.getId());
        mainEntityRepository.deleteById(id);
    }
}
```
4. Configure the application to work with a database:

In the `application.properties` file, add the following configuration:
```
spring.datasource.url=jdbc:postgresql://localhost:5432/mydatabase
spring.datasource.username=myusername
spring.datasource.password=mypassword
spring.jpa.hibernate.ddl-auto=update
```
5. Include the necessary dependencies in the `pom.xml` file:
```
<dependencies>
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-data-jpa</artifactId>
    </dependency>
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-web</artifactId>
    </dependency>
    <dependency>
        <groupId>org.postgresql</groupId>
        <artifactId>postgresql</artifactId>
    </dependency>
</dependencies>
```
6. Run the application:

To run the application, you can use the following command:
```
mvn spring-boot:run