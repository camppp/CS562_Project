#include "CommonTools/UtilAlgos/interface/SingleObjectSelector.h"

reco::CaloJetCollection selectJets(const reco::CaloJetCollection& jets, double minEt) {
  SingleObjectSelector<reco::CaloJetCollection> selector(minEt);
  selector.setCut(SelectorCut<reco::CaloJetCollection>(SelectorCut<reco::CaloJetCollection>::Et, minEt));
  return selector.select(jets);
}
