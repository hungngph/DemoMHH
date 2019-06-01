#include "Blockchain.h"

Blockchain::Blockchain()
{
	_vChain.emplace_back(Block(0, "Genesis Block"));
	/*như một khối được thêm vào blockchain, chúng cần tham chiếu khối
	trước bằng cách sử dụng hàm băm của nó, nhưng khi blockchain phải
	bắt đầu ở đâu đó, chúng ta phải tạo khối cho khối tiếp theo để tham
	chiếu, chúng ta gọi đây là khối genesis.Một khối genesis được tạo ra
	và được đặt lên vectơ _vChain*/

	_nDifficulty = 5;
	//thiết lập mức độ _nDiculticulty tùy thuộc vào mức độ khó mà 
	//chúng tôi muốn thực hiện quy trình PoW
}

Block Blockchain::_GetLastBlock() const
{
	return _vChain.back();
	//trả về khối cuối cùng được tìm thấy trong vector _vChain 
	//bằng cách sử dụng phương thức back
}

void Blockchain::AddBlock(Block bNew)
{
	bNew.sPrevHash = _GetLastBlock().GetHash();
	/*thiết lập biến sPrevHash cho khối mới từ mã băm của khối cuối cùng
	trên blockchain mà chúng ta sử dụng  _GetLastBlock  và phương thức
	GetHash của nó*/

	bNew.MineBlock(_nDifficulty);
	//khối này sau đó được khai thác bằng phương pháp MineBlock

	_vChain.push_back(bNew);
	//khối được thêm vào vectơ _vChain, 
	//do đó hoàn thành quá trình thêm một khối vào blockchain
}