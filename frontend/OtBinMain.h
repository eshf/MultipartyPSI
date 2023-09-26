#pragma once





//void OPPRFRecv();
//void OPPRFSend();
//void BarkOPRFRecv();
//void BarkOPRSend();
void Channel_test();
void OPPRF3_EmptrySet_Test_Main();
void OPPRFn_EmptrySet_Test_Main();
void OPPRF2_EmptrySet_Test_Main();
void Bit_Position_Random_Test();
void OPPRFnt_EmptrySet_Test_Main();
void party3(uint64_t myIdx, uint64_t setSize, uint64_t nTrials);
void party2(uint64_t myIdx, uint64_t setSize);
void party(uint64_t myIdx, uint64_t nParties, uint64_t setSize, std::vector<uint64_t>& mSet);
void tparty(uint64_t myIdx, uint64_t nParties, uint64_t tParties, uint64_t setSize, uint64_t nTrials);
void aug_party(uint64_t myIdx, uint64_t nParties, uint64_t setSize,uint64_t opt, uint64_t nTrials);
void OPPRFn_Aug_EmptrySet_Test_Impl();
void OPPRFnt_EmptrySet_Test_Impl();
void BinSize(uint64_t setSize, std::vector<uint64_t> set, uint64_t psiSecParam);