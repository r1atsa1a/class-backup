#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class TXT {
public:
	TXT();
	~TXT();
	void Enciper();
	void Deciper();
	void RandKEY();
	void outPlainTx();
	void outCiperTx();
	void outKeyTx();
private:
	string plain, cipher;
	string dict, key;
};
TXT::TXT() {
	plain = "Sky-Eagle行动失败，麻雀已牺牲，原先的信件交换地址已不安全，转移至衡兴北街586号C20信箱，请速与我联系。";
	dict = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0123456789!?;,:.@#$%^&()[]{}<>+-*/=_'";
}
TXT::~TXT() {
	
}
void TXT::Enciper() {
	// Sky-Eagle行动失败，麻雀已牺牲，原先的信件交换地址已不安全，转移至衡兴北街586号C20信箱，请速与我联系。
	// AaBbCcDdEeFfGgHhIiJjKkL
	cipher.clear();
	for (int i = 0; i < plain.size(); i ++) {
		int t;
		char tstr[5];
		if (plain[i] > 0) t = plain[i] ^ key[i % key.size()];
		else t = (-plain[i]) ^ key[i % key.size()];
		if (plain[i] > 0) cipher.push_back('0');
		else cipher.push_back('1');
		if (t < 10) cipher += "00";
		else if (t < 100) cipher += "0";
		itoa(t, tstr, 10);
		cipher += tstr;
	}
}
void TXT::Deciper() {
	plain.clear();
	for (int i = 0; i < cipher.size(); i += 4) {
		int t = 0, ans;
		for (int j = i + 1; j < i + 4; j ++)
			t = t * 10 + (cipher[j] - '0');
		ans = t ^ key[(i / 4) % key.size()];
		if (cipher[i] == '1') ans = -ans;
		plain.push_back(ans);
	}
}
void TXT::RandKEY() {
	srand((unsigned)time(NULL));
	for (int i = 0; i < plain.size() / 3; i ++) {
		int idx;
		idx = rand() % dict.size();
		key.push_back(dict[idx]);
	}
}
void TXT::outPlainTx() {
	cout << plain << endl;
}
void TXT::outCiperTx() {
	cout << cipher << endl;
}
void TXT::outKeyTx() {
	cout << key << endl;
}
int main() {
	TXT x;
	cout << "未加密 - 初始文本" << endl; x.outPlainTx();
	x.RandKEY();
	cout << "随机生成 - 密钥" << endl; x.outKeyTx();
	x.Enciper();
	cout << "密钥加密 - 文本" << endl; x.outCiperTx();
	x.Deciper();
	cout << "密钥解密 - 文本" << endl; x.outPlainTx();
	return 0;
}
