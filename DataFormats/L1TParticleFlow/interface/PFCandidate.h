#ifndef DataFormats_L1TParticleFlow_PFCandidate_h
#define DataFormats_L1TParticleFlow_PFCandidate_h

#include <vector>
#include "DataFormats/L1TMuonPhase2/interface/SAMuon.h"
#include "DataFormats/L1TParticleFlow/interface/PFTrack.h"
#include "DataFormats/L1Trigger/interface/RegionalOutput.h"

namespace l1t {

  class PFCandidate : public L1Candidate {
  public:
    typedef l1t::SAMuonRef MuonRef;
    typedef edm::Ptr<l1t::L1Candidate> L1CandPtr;
    enum ParticleType { ChargedHadron = 0, Electron = 1, NeutralHadron = 2, Photon = 3, Muon = 4 };

    PFCandidate() {}
    PFCandidate(ParticleType kind,
                int charge,
                const LorentzVector& p,
                float puppiWeight = -1,
                int hwpt = 0,
                int hweta = 0,
                int hwphi = 0)
        : PFCandidate(kind, charge, PolarLorentzVector(p), puppiWeight, hwpt, hweta, hwphi) {}
    PFCandidate(ParticleType kind,
                int charge,
                const PolarLorentzVector& p,
                float puppiWeight = -1,
                int hwpt = 0,
                int hweta = 0,
                int hwphi = 0);

    ParticleType id() const { return ParticleType(hwQual()); }

    const PFTrackRef& pfTrack() const { return trackRef_; }
    void setPFTrack(const PFTrackRef& ref) { trackRef_ = ref; }

    const L1CandPtr& caloPtr() const { return caloPtr_; }
    void setCaloPtr(const L1CandPtr& ptr) { caloPtr_ = ptr; }

    const MuonRef& muon() const { return muonRef_; }
    void setMuon(const MuonRef& ref) { muonRef_ = ref; }

    /// PUPPI weight (-1 if not available)
    float puppiWeight() const { return puppiWeight_; }

    void setZ0(float z0) { setVertex(reco::Particle::Point(0, 0, z0)); }
    void setDxy(float dxy) { dxy_ = dxy; }
    void setCaloEta(float caloeta) { caloEta_ = caloeta; }
    void setCaloPhi(float calophi) { caloPhi_ = calophi; }

    float z0() const { return vz(); }
    float dxy() const { return dxy_; }
    float caloEta() const { return caloEta_; }
    float caloPhi() const { return caloPhi_; }

    int16_t hwZ0() const { return hwZ0_; }
    int16_t hwDxy() const { return hwDxy_; }
    uint16_t hwTkQuality() const { return hwTkQuality_; }
    uint16_t hwPuppiWeight() const { return hwPuppiWeight_; }
    uint16_t hwEmID() const { return hwEmID_; }
    uint64_t encodedPuppi64() const { return encodedPuppi64_; }

    void setHwZ0(int16_t hwZ0) { hwZ0_ = hwZ0; }
    void setHwDxy(int16_t hwDxy) { hwDxy_ = hwDxy; }
    void setHwTkQuality(uint16_t hwTkQuality) { hwTkQuality_ = hwTkQuality; }
    void setHwPuppiWeight(uint16_t hwPuppiWeight) { hwPuppiWeight_ = hwPuppiWeight; }
    void setHwEmID(uint16_t hwEmID) { hwEmID_ = hwEmID; }
    void setEncodedPuppi64(uint64_t encodedPuppi64) { encodedPuppi64_ = encodedPuppi64; }

  private:
    L1CandPtr caloPtr_;
    PFTrackRef trackRef_;
    MuonRef muonRef_;
    float dxy_, puppiWeight_, caloEta_, caloPhi_;

    int16_t hwZ0_, hwDxy_;
    uint16_t hwTkQuality_, hwPuppiWeight_, hwEmID_;
    uint64_t encodedPuppi64_;

    void setPdgIdFromParticleType(int charge, ParticleType kind);
  };

  typedef std::vector<l1t::PFCandidate> PFCandidateCollection;
  typedef edm::Ref<l1t::PFCandidateCollection> PFCandidateRef;
  typedef edm::RefVector<l1t::PFCandidateCollection> PFCandidateRefVector;
  typedef l1t::RegionalOutput<l1t::PFCandidateCollection> PFCandidateRegionalOutput;
}  // namespace l1t
#endif
