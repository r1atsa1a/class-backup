# Encryption

已知一段加密后的英文段落如下。

```
B!ofx!jowfstf!ifbu!dpoevdujpo!gsbnfxpsl!gps!4E!jnbhjoh!sfdpotusvdujpo!jt!qspqptfe!jo!uijt!qbqfs/!Gjstu-!uif!cbtjd!jefb!up!vtf!uif!JID!gps!4E!ebnbhf!jnbhjoh!jt!ejtdvttfe!boe!gpsnvmbufe/Uif!qspqptfe!JID!jodmveft!uisff!nbkps!dpnqpofout;!gpsxbse!uifsnbm!bobmztjt!tpmwfs-!bekpjou!nfuipe!gps!fggjdjfou!tfotjujwjuz!bobmztjt-!boe!dpokvhbuf!hsbejfou!nfuipe!xjui!dpotusbjout!gps!pqujnbm!jowfstf!tpmvujpot/!Gpmmpxjoh!uijt-!uif!qspqptfe!JID!gsbnfxpsl!jt!bqqmjfe!up!b!tjnqmf!pof!ejnfotjpobm!qspcmfn!up!jmmvtusbuf!uif!lfz!tufqt/!Ofyu-!uxp!bqqmjdbujpo!fybnqmft!jo!4E!bsf!jowftujhbufe/!Tqfdjbm!gpdvtft!po!uif!efufdubcjmjuz-!dpowfshfodf-!boe!spcvtuoftt!bsf!ejtdvttfe!jo!efubjm/!Gjobmmz-!tfwfsbm!dpodmvtjpot!boe!gvuvsf!xpsl!bsf!esbxo!cbtfe!po!uif!qspqptfe!tuvez!boe!ovnfsjdbm!sftvmut/
```

- Level 1：将原加密文本解密。
- Level 2：使用更高强度的算法将原文再次加密。
- Level 3：将加密后的文本再次解密。

Tips：使用C++类的形式进行声明和定义。

## 程序运行结果

朴素解密后文本如下

```
A new inverse heat conduction framework for 3D imaging reconstruction is proposed in this paper. First, the basic idea to use the IHC for 3D damage imaging is discussed and formulated.The proposed IHC includes three major components: forward thermal analysis solver, adjoint method for efficient sensitivity analysis, and conjugate gradient method with constraints for optimal inverse solutions. Following this, the proposed IHC framework is applied to a simple one dimensional problem to illustrate the key steps. Next, two application examples in 3D are investigated. Special focuses on the detectability, convergence, and robustness are discussed in detail. Finally, several conclusions and future work are drawn based on the proposed study and numerical results.
```

随机生成密钥

```
${-EDE,bZU-vDK4$@Rnt7vxeGTv!1DoR*X;a2?NhHV<k!xMuH&HdO9I!F75=:_1-WoJebWxt_T++
```

密钥加密后文本

```
J|3y,H_{A|n|zkn!IAtN5g/yB|o[-z/6mva7&4N?EaH*Rh|Dqp=C^5^m|az<-Jn|Rlm=b|Dasd|,$!Yb)O|!G]G|3v:J_c|%3ynnP|HC4Fq^:T|L@A|B|t}QT|L|(S}uaUOac/o|Wg9[%B^y{m|F2<actRfGc:LaQd|;a|Vf|a|^20d)3qz.K%fdwvoK!AC!GZA|*7N'C|.g|}Tm8a7-vNv']F/1wMopOcc|W)1DY:@A6X#oC=*VE|d|(C|J|3j,s3b*Qf|v:J<(^9zCE2:F9nP|a#tD|N|km1>W]8@y.r/UI/)A|RuN6[%g_yF9nf|b|@N2UlE=B|kA9u_a|Xup&O|?G.G|quC|L]'f1T|nGP|DArbtC|<T|&*kb|0{!b|Rc6;h|2cyahA|stMq]:,c|Yc|m|.3'&Bn|Qfia'MB9DCN4Vm@qxH.2f|Qc|e,C|#9T|Mm6fi6AP|D|c|5N{,A|x;7]8Ft#h|o5i=)'5QOv+Jk/9.2H2=ajQTBgOA|ngm|S(/J|h|c@TrH]vsG|*h]C|:Q2dLZi#!aZ@+2b|B|<l0{xmvfQ+wMK|G}B-8Wek|j;C]0#q}3'+h4Tfm=B|kbQs[;J|QC[RUg(G|s|2A|k,#@SZnnP|IFQH6g*6^/,l1@w[rdT}h|2cyahA|stMq]:,c|Ys|r|fq#;NqVllIlIAzd|;>43b{TzDG2wG|(k][(52*oYbEvfP|I|BT|^+-lcI|AmVG8DwD4'{pO3wGtp>E^5^m|FW#aa|Q0liYla|O3Y#@J|3p#qq|G#G|QQc|K*@A|ST|diP|GFrn0'.v&-a|*r-I|c|qgx%sOK|8J){5X^s]C|Lc|1)Qef|D|{pQSIOM'l{Tq,b|J|qcD|YWG#G|zQ.B|G|
```

> Last Update in 2022/09/29