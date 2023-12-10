#include <gtest/gtest.h>
#include "EHTTools.h"

TEST(EHTTools, RunMol) {
  // Setup molecule and result objects
  Molecule molecule("H2O");
  Result result;

  // Run simulation on molecule
  EHTTools::runMol(molecule, result);

  // Verify number of electrons
  REQUIRE_EQ(result.getNumElectrons(), 2);

  // Verify number of orbitals
  REQUIRE_EQ(result.getNumOrbitals(), 3);

  // Verify number of atoms
  REQUIRE_EQ(result.getNumAtoms(), 3);

  // Verify properties of atoms
  CHECK_EQ(result.getAtom(0).getSymbol(), "H");
  CHECK_EQ(result.getAtom(1).getSymbol(), "O");
  CHECK_EQ(result.getAtom(2).getSymbol(), "H");

  // Verify properties of bonds
  CHECK_EQ(result.getBond(0).getOrder(), 2);
  CHECK_EQ(result.getBond(1).getOrder(), 1);

  // Verify properties of molecular orbitals
  CHECK_EQ(result.getMolecularOrbital(0).getEnergy(), 10);
  CHECK_EQ(result.getMolecularOrbital(1).getEnergy(), 20);
  CHECK_EQ(result.getMolecularOrbital(2).getEnergy(), 30);
}
