import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;

@Entity
@Table(name = "T_ONLINE")
public class Tonline {
    @Id
    private Long id;

    @Temporal(TemporalType.TIMESTAMP)
    private Date lastOnlineTime;

    // getters and setters
}