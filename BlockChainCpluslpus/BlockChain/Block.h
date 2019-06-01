#include <cstdint>
#include <iostream>
#include <sstream>

using namespace std;

class Block {
public:
	string sPrevHash; //nhớ mỗi khối được liên kết với khối trước đó

	Block(uint32_t nIndexIn, const string &sDataIn);
	/*từ khóa const được sử dụng cùng với công cụ sửa đổi tham chiếu
	( & ) để các thông số được truyền theo tham chiếu nhưng không thể thay
	đổi, điều này được thực hiện để cải thiện hiệu quả và tiết kiệm bộ nhớ*/

	string GetHash();

	void MineBlock(uint32_t nDifficulty);

private:
	uint32_t _nIndex;
	int64_t _nNonce;
	string _sData;
	string _sHash;
	time_t _tTime;

	string _CalculateHash() const;
	/*từ khóa const, điều này là để đảm bảo đầu ra từ phương thức
	không thể thay đổi, điều này rất hữu ích khi xử lý một blockchain*/
};