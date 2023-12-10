#include "FWCore/Framework/interface/MakerMacros.h"
#include "CommonTools/UtilAlgos/interface/EtMinSelector.h"
#include "CommonTools/UtilAlgos/interface/SingleObjectSelector.h"
#include "DataFormats/JetReco/interface/CaloJet.h"

reco::CaloJetCollection selectJets(const reco::CaloJetCollection& jets, double minEt) {
    // Define the EtMinSelector using the provided minimum Et threshold
    EtMinSelector<reco::CaloJet> etMinSelector(minEt);

    // Create a SingleObjectSelector using the EtMinSelector
    SingleObjectSelector<reco::CaloJetCollection, EtMinSelector<reco::CaloJet>> jetSelector(etMinSelector);

    // Apply the selection to the input jet collection
    reco::CaloJetCollection selectedJets = jetSelector(jets);

    return selectedJets;
}
