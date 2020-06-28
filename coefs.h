// Scrambler coefficients
uint64_t taps = (1ull << 42) + (1ull << 40) + (1ull << 37) + (1ull << 35) + 1;
const int seq_length = 128;
const int jump = 987654;
char magic[8] = {0x35, 0x75, 0x65, 0x7a, 0x53, 0x04, 0x6c, 0x77};
