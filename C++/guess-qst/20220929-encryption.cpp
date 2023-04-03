#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class TXT {
    public:
        TXT();
        ~TXT();
        void EnciperPRO();
        void Deciper();
        void DeciperPRO();
        void RandKEY();
        void outPlainTx();
        void outCiperTx();
        void outKeyTx();
    private:
        string plain, cipher;
        string dict, key;
};
TXT::TXT() {
    cipher = "B!ofx!jowfstf!ifbu!dpoevdujpo!gsbnfxpsl!gps!4E!jnbhjoh!sfdpotusvdujpo!jt!qspqptfe!jo!uijt!qbqfs/!Gjstu-!uif!cbtjd!jefb!up!vtf!uif!JID!gps!4E!ebnbhf!jnbhjoh!jt!ejtdvttfe!boe!gpsnvmbufe/Uif!qspqptfe!JID!jodmveft!uisff!nbkps!dpnqpofout;!gpsxbse!uifsnbm!bobmztjt!tpmwfs-!bekpjou!nfuipe!gps!fggjdjfou!tfotjujwjuz!bobmztjt-!boe!dpokvhbuf!hsbejfou!nfuipe!xjui!dpotusbjout!gps!pqujnbm!jowfstf!tpmvujpot/!Gpmmpxjoh!uijt-!uif!qspqptfe!JID!gsbnfxpsl!jt!bqqmjfe!up!b!tjnqmf!pof!ejnfotjpobm!qspcmfn!up!jmmvtusbuf!uif!lfz!tufqt/!Ofyu-!uxp!bqqmjdbujpo!fybnqmft!jo!4E!bsf!jowftujhbufe/!Tqfdjbm!gpdvtft!po!uif!efufdubcjmjuz-!dpowfshfodf-!boe!spcvtuoftt!bsf!ejtdvttfe!jo!efubjm/!Gjobmmz-!tfwfsbm!dpodmvtjpot!boe!gvuvsf!xpsl!bsf!esbxo!cbtfe!po!uif!qspqptfe!tuvez!boe!ovnfsjdbm!sftvmut/";
    dict = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0123456789!?;,:.@#$%^&()[]{}<>+-*/=_'";
}
TXT::~TXT() {
    
}
void TXT::EnciperPRO() {
    cipher.clear();
    for (int i = 0; i < plain.size(); i ++) {
        int t;
        t = plain[i] ^ key[i % key.size()];
        if (t < dict.size()) cipher.push_back(dict[t]);
        else {
            t -= dict.size();
            cipher.push_back('|');
            cipher.push_back(dict[t]);
        }
    }
    reverse(cipher.begin(), cipher.end());
}
void TXT::Deciper() {
    for (int i = 0; i < cipher.size(); i ++) {
        if (cipher[i] == '!') plain.push_back(' ');
        else plain.push_back(cipher[i] - 1);
    }
}
void TXT::DeciperPRO() {
    plain.clear();
    reverse(cipher.begin(), cipher.end());
    int cnt = 0, outerAscii = 0;
    for (int i = 0; i < cipher.size(); i ++) {
        int t;
        if (cipher[i] == '|') {outerAscii = 1; continue; }
        if (!outerAscii) t = dict.find(cipher[i]) ^ key[cnt % key.size()];
        else {
            t = (dict.find(cipher[i]) + dict.size()) ^ key[cnt % key.size()];
            outerAscii = 0;
        }
        cnt ++;
        plain.push_back(t);
    }
}
void TXT::RandKEY() {
    srand((unsigned)time(NULL));
    for (int i = 0; i < cipher.size() / 10; i ++) {
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
    cout << "已加密 - 初始文本:" << endl; x.outCiperTx();
    x.Deciper();
    cout << "朴素解密 - 文本:" << endl; x.outPlainTx();
    x.RandKEY();
    cout << "随机生成 - 密钥:" << endl; x.outKeyTx();
    x.EnciperPRO();
    cout << "密钥加密 - 文本:" << endl; x.outCiperTx();
    x.DeciperPRO();
    cout << "密钥解密 - 文本:" << endl; x.outPlainTx();
    return 0;
}