package com.bol.repository;

import com.bol.model.Pit;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;
import java.util.UUID;

@Repository
public interface PitRepository extends CrudRepository<Pit, UUID> {
    Pit findPitById(UUID id);
}