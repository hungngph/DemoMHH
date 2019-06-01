#include <time.h>
#include "Block.h"
#include "sha256.h"		
Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
	_nNonce = -1;
	_tTime = time(nullptr);
}


string Block::GetHash()
{
	return _sHash;
}


void Block::MineBlock(uint32_t nDifficulty)
{
	char * cstr = new char[nDifficulty + 1];
	//tạo một mảng các ký tự có độ dài lớn hơn một giá trị được chỉ định cho nDifficulty

	for (uint32_t i = 0; i < nDifficulty; ++i) {
		cstr[i] = '0';
	}
	//vòng lặp for được sử dụng để điền vào mảng bằng số không

	cstr[nDifficulty] = '\0';
	//mục mảng cuối cùng được cho ký tự kết thúc chuỗi (\0)

	string str(cstr);
	//chuỗi cstr được biến thành một chuỗi chuẩn

	do {
		_nNonce++;
		_sHash = _CalculateHash();
	} while (_sHash.substr(0, nDifficulty) != str);
	/*do ... while để tăng _nNonce và _sHash được gán với đầu ra của _CalculateHash,
	phần trước của băm sau đó được so sánh với chuỗi số không mà chúng
	ta vừa tạo; nếu không có kết quả phù hợp, vòng lặp được lặp lại cho
	đến khi tìm thấy kết quả phù hợp.Khi một kết quả trùng khớp được tìm
	thấy, một thông báo sẽ được gửi đến bộ đệm đầu ra để nói rằng khối đã
	được khai thác thành công*/


	cout << "Block mined: " << _sHash << endl;
}


inline string Block::_CalculateHash() const {
	stringstream ss;
	ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;
	//nối các giá trị cho _nIndex, _tTime, _sData, _nNonce và sPrevHash vào luồng

	return sha256(ss.str());
	/*kết thúc bằng cách trả về đầu ra của phương thức sha256
	(từ các tệp sha256 mà chúng tôi đã thêm trước đó) bằng cách
	sử dụng đầu ra chuỗi từ luồng chuỗi*/

}