
#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;
class Blockchain {
public:
	Blockchain();

	void AddBlock(Block bNew);

private:
	uint32_t _nDifficulty;
	vector<Block> _vChain;

	Block _GetLastBlock() const;
	/*const t? kh�a ?? bi?u th? r?ng ??u ra c?a ph??ng th?c kh�ng th? thay ??i*/
};
