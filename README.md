# 自作関数によるc標準関数による実装
24入社の増田と申します，よかったら参考にしてね！  
初学者に分かりやすいように解説しているので，経験者の人は我流でやって全然いいと思います  
自分のc言語能力はatcoderレート700程度だと思います（サブ垢でc言語一筋でランクあげてます）

# プログラミングをする前に気をつけること
## 環境構築
### 名前の似ている3つのソフト
よくある勘違いとして，

- Visual Studio (VS)
- Visual Studio Installer
- Visual Studio Code  

のこれらはそれぞれ異なるアプリケーションです．  
まずwebサイトでVisual Studio Installerをダウンロードし，Visual Studio Installerを用いてVisual Studioをインストールします．  
今回の課題をするにあたってVSCは必須ではありません．

### プログラムが実行できるまで
メールで送られてきた https://jet-blog.com/clang_lesson002/ に従い作業してください．  
たぶん2022年版を推奨されますが，2019でも2022でも変わらないと思います．  
これらに注意して一通りインストールできたらエクスプローラとデバッグ出力を表示させておくと便利だと思います．  

<img src="/img/vsstatus.png" alt="vsstatus" width="480">

またコーディング自体はVScodeを使うともっと楽だと思いますがパソコンに慣れてないならVSで問題ないです．  
上の画像のような状況で |> ローカルwindowsデバッガー を押して下の画像のようにステータス0で終了していれば正常終了している状況です．  

<img src="/img/exitw0.png" alt="exitw0" width="480">

うまくいかなかったら画面共有とかで教えられるかもです．

## 課題の根本的な理解
### 記述するファイル
まず，私たちが記述するべきファイルは，

- CBasic/Std/Src/StdChr.c 文字処理のプログラム
- CBasic/Std/Src/StdStr.c 文字列処理のプログラム
- CBasic/Std/Src/StdArt.c 算術処理のプログラム

の3つです．  
場合によってヘッダファイルに追加記述してもいいと思いますが，初心者の人はやめておいた方が良いと思います．  
これらのファイルはc言語で記述され， |> ローカルwindowsデバッガー を押すたびにコンパイルされます．
CBasic/Std/Src/StdChr.c の意味がわからない人は https://www.pc-master.jp/words/directory.html にてディレクトリについてざっくり理解しておきましょう．

これらの変更が正しいのかどうかを CBasic/Std/Debug/CBasic.exe が判定します．

### 自作関数の作成と標準関数の仕様理解
課題は，c言語のヘッダファイルで提供されている標準関数を自作するものです．  
そのためにまず標準関数の仕様を理解する必要があります．  
課題のうちの一つに「文字が英小文字か」を判定する標準関数 Islower を自作するものがあります． 

また，ログファイルから出力の違いを確認したり，printf文で吐き出させたりすることで問題を解決できる場合もあります．

### 記述したプログラムの評価とその確認
これらのテキストファイルの変更が，正しい記述であるかの判断はPHRの作成したテストを用いて行われます．  
テストはいくつかの頻出する例を入力として，標準関数と自作関数との戻り値を比較し，プログラムが正しいかを判定しているみたいです．  

<img src="/img/testflow.png" alt="exitw0" width="480">

PHRが用意した有限個の入力 $x_1, x_2, x_3, ..., x_n$ に対して，  
標準関数 $f$ の出力 $f(x_1), f(x_2), f(x_3), ..., f(x_n)$ と  
自作関数 $g$ の出力 $g(x_1), g(x_2), g(x_3), ..., g(x_n)$ に対して，  
$f$ と $g$ の距離 $\sum_{n=1}^n (f(n) - g(n))^2$ が  
0なら「OK」の判定，  
0でなければ「NG」の判定を得ます．（画像のフローが理解できていれば十分です）  

判定結果は CBasic/log から確認でき，一つの関数に対して一つのログファイルが出力されます．

- CBasic/log/01-~~~.log はStdChr.cの結果
- CBasic/log/02-~~~.log はStdStr.cの結果
- CBasic/log/03-~~~.log はStdArt.cの結果

となっています．  
ただそれ以降のナンバリングはソースコードの順番と一致していないので逐次確認する必要があります．

例えば 01-06-001.log は入力が英小文字かどうかを判定するプログラムが正しいかを記録しているログファイルですが，
正しい記述をすると

``````
/*******************************************************************************/
UT Start Function:StdChr_Islower
/*******************************************************************************/
Test Function Execute:StdChr_Islower

文字が英小文字（'a'～'z'）か検査

入力 : 0x00
標準関数 : 0x00
自作関数 : 0x00
標準関数と自作関数の比較 : OK

入力 : 0x7f
標準関数 : 0x00
自作関数 : 0x00
標準関数と自作関数の比較 : OK

入力 : `
標準関数 : 0x00
自作関数 : 0x00
標準関数と自作関数の比較 : OK

入力 : a
標準関数 : 0x02
自作関数 : 0x02
標準関数と自作関数の比較 : OK

入力 : b
標準関数 : 0x02
自作関数 : 0x02
標準関数と自作関数の比較 : OK

入力 : y
標準関数 : 0x02
自作関数 : 0x02
標準関数と自作関数の比較 : OK

入力 : z
標準関数 : 0x02
自作関数 : 0x02
標準関数と自作関数の比較 : OK

入力 : {
標準関数 : 0x00
自作関数 : 0x00
標準関数と自作関数の比較 : OK
``````

となり，入力値，標準関数の出力値，自作関数の出力値，比較判定を確認できます．
なにも記述していないと，ほとんどがNGなので，この表示をOKにすることが課題の本質であることを理解しましょう．

# プログラミングをするときに気をつけること
## 直接的なこと
### 変数の型について(typedef)
整数型の変数aを確保するときに，c言語では

```c
int a;
```

みたいな記述をしますが，課題では

```c
int32t a;
```

という記述を確認できます．  
これはソースコード内で読み込んでいる StdCommon.h にある以下の記述が関係しています．

```c
/* ************************************************************************** */
/* typedef 定義                                                               */
/* ************************************************************************** */
typedef char                    char8t;
typedef unsigned char           uchar8t;
typedef int                     int32t;
typedef long long int           llint64t;
typedef unsigned long long int  ullint64t;
typedef unsigned int            uint32t;
typedef signed int              sint32t;
typedef double                  double64t;
typedef long double             ldouble80t;
```

typedef はc言語が提供している変数型の名前を変更するキーワードです．  
https://programming.pc-note.net/c/typedef.html  

int でも動くと思いますが，ひとまずこの記述に従った方がよさそうです．  
どの変数がどの宣言をしているか分からない場合は，ここにきて確認しましょう．

### 同じ内容の記述を複数の場所で行う(OAOO原則)
プログラミングでは，同じ内容の処理を何度も異なる場所で書かないようにしましょう(Once And Only Once)．  
これは勘違いなどでコードを変更するとき，何か所も変更するのがめんどうであるし，運用保守の面でもおおきな負債となる場合が多いからです．  
本当に極端な例ですが，以下に二つの同じ結果を得るコードを記します．

```c
// 悪い例
int func(int input) {
    int ret = input;
    if(input == 0) {
        puts("関数の戻り値は6です．");
        return 6;
    } else if(input == 1) {
        puts("関数の戻り値は28です．");
        return 28;
    } else if(input == 2) {
        puts("関数の戻り値は496です．");
        return 496;
    } else if(input == 3) {
        puts("関数の戻り値は8128です．");
        return 8128;
    } else if(input == 4) {
        puts("関数の戻り値は33550336です．");
        return 3550336;
    } 

    return ret;
}

// 良い例
void call(int input) {
    printf("関数の戻り値は%dです．", input);
}

int func(int input) {
    int ret[] = {6, 28, 496, 8128, 3550336};
    if(0 <= input && input <= 4) {
        call(ret[input]);
        return ret[input];
    } else {
        return input;
    }
}

```

もしinputが0だったときの戻り値を6から7にしたくなったら，悪い例では修正は2箇所，良い例では修正は1箇所になります．  
もし出力文の最後を「．」ではなく「！」にしたくなったら，悪い例では修正は5箇所，良い例では修正は1箇所になります．  
何回も同じ処理をするなら関数を呼び出したり，何回も同じ比較をするなら配列を使ったりすることでOAOO原則にのっとった記述が可能になります．  

## マクロで気をつける事
### テストコードの穴とプログラマの責任
例えば uint32t StdChr_Isalnum(uint32t aC) の aC には，32ビットの整数型，つまり2の32乗である約42億通りの入力がありえます．
関数型言語の記述をする以上，ありえる全ての入力に対し，ただひとつの出力をする関数を記述する必要があります．

しかしログファイルを確認すると分かるとおり，テストコードでは 0x00, 0x7f, /, 0, 1, 8, 9, :, @, A, B, Y, Z, [, ``, a, b, y, z, { のたかだか20種類の入力に対する出力の違いを比較していますが，プログラムを記述する際はテストで用いる値だけでなく入力としてあり得るすべての範囲の値について配慮する必要があります．

<img src="/img/testcode.png" alt="testcode" width="480">

### ヘッダファイルに書いてあること
ヘッダファイルは私たちが記述するプログラムの最初にインポートされます．  

```c
#define DEF_STDCHR_0    0U
```
この記述があるので， DEF_STDCHR_0 は 0 を意味します．  
また，ソースファイルに最初から書かれている関数はヘッダファイルにてプロトタイプ宣言されているので，もう一度書く必要はありません．

### 自作関数は「自作」関数である
当然ですが，自作関数を作成するにあたって標準関数を使ってはいけません．  
```c
uint32t StdChr_Isalnum(uint32t aC)
{
    /* 戻り値の初期化 */
    uint32t tRet = DEF_STDCHR_0;

    /* ここに実装してください。 */
    tRet = isalnum('a');

    return tRet;
}
```
これは ctype.h にて提供されている標準関数 isalnum を用いた実装です．やめてね  

# StdChr
## StdChr_Isupper
与えられた入力が英大文字かどうかを判定する関数です．  
ログファイルは 01-10-001.log より確認できます．  

### インターネットで調べてみよう
google検索で「c言語 isupper」で検索してみましょう．  
以下は https://bituse.info/c_func/23 より一部引用．

```
isupper関数は引数の英字が大文字かどうかを調べてくれます。
戻り値は、引数の英字が大文字なら０以外の値を返し、
大文字じゃなければ０を返します。
```

### ログファイルを見てみよう
01-10-001.log より，どんな入力に対しどんな出力を得るか見てみましょう．  
以下はログファイルより一部引用．

```
入力 : @
標準関数 : 0x00

入力 : A
標準関数 : 0x01
```

0x~~ は16新法表記です．  
0x00 は10進数で 0， 0x01 は10進数で 1 ですね．  
見る限り英大文字であれば 1 を返し，英大文字でなければ 0 を返すようです．

### 実装してみよう
まず私が記述したプログラムを記します．

```c
uint32t StdChr_Isupper(uint32t aC)
{
    /* 戻り値の初期化 */
    uint32t tRet = DEF_STDCHR_0;

    /* ここに実装してください。 */
    if(aC >= 'A' && aC <= 'Z') {
        return 0x01;
    } else {
        return tRet;
    }

    return tRet;
}
```

切り分けて解説します．  

```c
uint32t StdChr_Isupper(uint32t aC)
```
StdChr_Isupperという名前の関数は戻り値がuint32t型であり，入力はuint32t型の変数aCです．

```c
uint32t tRet = DEF_STDCHR_0;
```
変数tRet(戻り値)を宣言し，初期値は0とします．

```c
if(aC >= 'A' && aC <= 'Z') {
    return 0x01;
}
```
aC >= 'A' という比較文， aC <= 'Z' という条件の両方が真であるときに限り， retrun 0x01 が実行されます．  
ASCIIコード表 http://www3.nit.ac.jp/~tamura/ex2/ascii.html を見てみるとAの文字コードは65，そこからB,C,D,と続いていき，Zの文字コードは90となっています．  
つまり上のプログラムは aC >= 65 && aC <= 90 と同じです．  
&& は論理積を意味し，図のようにaCの値がAに対応する値より大きい かつ aCの値がZに対応する値より小さい 場合に，関数は1を返します．

<img src="/img/isupper.png" alt="isupper" width="480">

```c
else {
        return tRet;
    }
```
そして，aCがAより小さかったり，Zより大きかったりした場合は，関数は0を返します．  

これと同じ要領で，

- StdChr_Isdigit
- StdChr_Islower

が実装できるのでぜひやってみてください．

## StdChr_Isalpha
与えられた入力が英文字かどうかを判定する関数です．  
ログファイルは 01-02-001.log より確認できます．  

また，この関数の実装には

- StdChr_Isdigit
- StdChr_Islower

を既に実装している必要があります．

### ログファイルを見てみよう
ログファイルを見てみると

- 大文字の場合は1
- 小文字の場合は2
- どちらでもなければ0

を返す関数のようです．

### 実装してみよう
```c
uint32t StdChr_Isalpha(uint32t aC)
{
    /* 戻り値の初期化 */
    uint32t tRet = DEF_STDCHR_0;

    /* ここに実装してください。 */
    if(StdChr_Isupper(aC)) {
        return 0x01;
    } else if(StdChr_Islower(aC)) {
        return 0x02;
    } else {
        return 0x00;
    }

    return tRet;
}
```
OAOO原則に則り，同じ内容を何回も書くのはやめましょう．  
大文字かの判定，小文字かの判定は既に記述している関数を利用しましょう．

これと同じ要領で，

- StdChr_Isalnum

が実装できるのでぜひやってみてください．

## StdChr_Tolower
与えられた入力が大文字であれば，小文字に変換した値を返し，大文字でなければそのままの値を返す関数です．  
ログファイルは 01-12-001.log より確認できます．  

### 実装してみよう
asciiコードを見てみると，大文字と同じように小文字も連番に配置されていることが分かると思います．  
つまり，Aとaの値の差は，Bとb，Cとc，と同じ値になります．
ただ，処理系依存にならないように aC += 32 と書くのはよろしくないと思います．  
フローチャートを書いてみるとこのようになります．

<img src="/img/tolower.png" alt="tolower" width="480">

これと同じ要領で

- StdChr_Toupper

を実装することができます．

# StdStr
## StdStr_Strerror
与えられた入力に対応するエラーメッセージを標準ストリームへ出力する
ログファイルは 02-11-001.log より確認できます．  

### ログファイルを見てみよう
02-11-001.log より，どんな入力に対しどんな出力を得るか見てみましょう．  
見てみるとエラー番号0から40までの整数に対応するエラーメッセージが確認できます．

### 標準関数をぶったたいてみる
ログには0から40だけの出力を確認できますが，
ここに41以上とか-1以下の整数に対しての出力は提供されていないのかが分からないので
以下のプログラムを適当な関数内で呼び出してみてください

```c
for(int i = -10; i < 100; i++) {
    char* p = strerror(i);
    printf("%d %s\n", i, p);
}
```

で値域が本当に0から40なのか，また地域外の入力に対してはどのような文字列を返却するとかを確認しましょう．
一部引用でこんな感じ

```
-3 Unknown error
-2 Unknown error
-1 Unknown error
0 No error
1 Operation not permitted
2 No such file or directory
3 No such process
```

自分で確認すること！

### 実装してみよう
実装するにあたってメモリについて一度確認します．
c言語は関数の実行時にメモリを確保し（関数内の変数の所在が確定している），
他の関数やプロセスが使えるように関数の終了時にメモリを解放します（関数内の変数を参照できなくなる）．
よって，関数内のポインタを関数の戻り値にすると，テストプログラムが確認するときに開放済みのメモリを参照してしまいます．
これでうまくいく場合もありますが（たぶん3回に2回とか？），windowsで走る他のプログラムによって汚されている場合があるのでやめましょう．
また，最終的に同じ結果を得られるならばプログラムが占有するメモリは小さい方が良いので，
確保するグローバル変数はなるべく小さくしましょう．

ここらへんはdiscordで画像で解説してます．

で結局こんな実装になりました．
```c
char8t* StdStr_Strerror(int32t aErrnum)
{
    /* 戻り値の初期化 */
    char8t* tpRet = "Unknown error";

    /* ここに実装してください。 */
    char8t message[44][80] = {
        "No error",
        "Operation not permitted",
        "No such file or directory",
        "No such process",
        "Interrupted function call",
        "Input/output error",
        "No such device or address",
        "Arg list too long",
        "Exec format error",
        "Bad file descriptor",
        "No child processes",
        "Resource temporarily unavailable",
        "Not enough space",
        "Permission denied",
        "Bad address",
        "Unknown error",
        "Resource device",
        "File exists",
        "Improper link",
        "No such device",
        "Not a directory",
        "Is a directory",
        "Invalid argument",
        "Too many open files in system",
        "Too many open files",
        "Inappropriate I/O control operation",
        "Unknown error",
        "File too large",
        "No space left on device",
        "Invalid seek",
        "Read-only file system",
        "Too many links",
        "Broken pipe",
        "Domain error",
        "Result too large",
        "Unknown error",
        "Resource deadlock avoided",
        "Unknown error",
        "Filename too long",
        "No locks available",
        "Function not implemented",
        "Directory not empty",
        "Illegal byte sequence",
        "Unknown error"
    };

    for(int32t i = 0; i < 43; i++) {
        if(aErrnum == i) {
            StdStr_Strcpy(&em[0], &message[i][0]);
            return &em[0];
        }
    }

    StdStr_Strcpy(&em[0], &message[44][0]);
    return &em[0];
}
```

ログファイルから確認できない範囲のメッセージ，また本来存在しない範囲もカバーしてるつもりです．
のせてるけどあんま露骨なコピペしないでね

# StdArt
算術計算(StdArt)はそのほとんどが他の関数から導出できるため，まずいくつかのプライマリな関数から作成することで，それ以降の関数の実装を爆速にすることができます．

## まとめ
これだけ見て分かる人はこれを見て進めてください

## 定数定義
プログラミングをするにあたって，どうしても $\pi$ だけは用意しないと立ちどころに困るので宣言しておきましょう
```c
#define PI  3.141592653589793238462643 //pi
```

## StdArt_Fmod
Fmod関数は $aX/aY$ のあまりを返却します，ただし引数は整数ではなく浮動小数点です．

最初は $aY$ の定義域について言及しましょう．
```c
if(aY == 0.0) {
    return NAN;
}
```

次に本命の処理を考える時に，浮動小数点同士の「%」演算子はサポートしていない反面，「/」はサポートしている点に注目しましょう．

本来 aX/aY のあまりは aX/aY の結果を整数で切り落としたときの解 $x$ から，$x$ に aY をかけたもの $x * aY$ と $aX$ の差のはずです．

14.5/3.5 = 4 mod 0.5 は 14.5/3.5 の結果4.1428...を整数で切り落としたときの解4から，4に3.5をかけたもの4*3.5=14と14.5の差0.5のはずです．

具体的な手順は

1. aX/aY を計算する

2. 1.を整数に丸める

3. 2.をaYでかける

4. 3.とaXの差を求める

## StdArt_Sin
sin関数は入力された角度に対応する正弦値を返却する関数です．

導出にはマクローリン展開を用います．

高校数学範囲なので覚えていない人は復習しましょう．

最初は $aX$ の定義域について言及しましょう．

マクローリン展開はその性質上 aX が 0 から遠ざかるほど精度が悪化するため， $\sin(2\pi + x) = \sin(x)$ を用いて aX の範囲を 閉区間 $[\pi, \pi]$ に丸めましょう．

これをしないとaXに100とか来た時死にます．

次に本命のマクローリン展開のについての公式を置きます．

$f(x) ~ f(0) + f'(0)x + \frac{f''(0) * x^2}{2!} + \frac{f'''(0) * x^3}{3!} + ...... + \frac{f^{(n)}(0) * x^n}{n!}$

ここでは， f^{(n)}(0) と x^n と n! の3つにわけて考えましょう．実際のプログラムはn=0の初期値からn=1の値を導出し，n=1の値からn=2の値を導出し，誤差が許容できるまでn=xxの値からn=xx+1を導出します．

f^{(n)}(0) すなわち sin^{(n)}(0) は 0, 1, 0, -1 を繰り返す項です．これよりnが偶数の時はなにになにをかけても0のため計算する意味はありません．

x^n はもちろん n をかけてやると次の世代の x^{n+1} になります．

n! はもちろん n+1 をかけてやると次の世代の (n+1)! になります．

これと同じ方法で Exp も解きましょう．

## 他の関数の解き方
### StdArt_Sqrt
x軸とy軸を反転させることで，root(1/2乗)は2乗の方程式を解くことになります．  
十分に精度を担保できるまで続けます．
```c
double64t StdArt_Sqrt(double64t aX)
{
    /* 戻り値の初期化 */
    double64t tRet = DEF_STDART_D0;

    /* ここに実装してください。 */
    if(aX < 0.0) {
        return NAN;
    }

    double64t tmpx, newx = 10.0;
    do {
        tmpx = newx;
        newx = tmpx - (tmpx * tmpx - aX) / (2 * tmpx);
    } while(StdArt_Fabs(newx - tmpx) > 0.000001);
    tRet = newx;

    return tRet;
}
```

### StdArt_Cos
$\cos(x) = \sin(x + \frac{\pi}{2})$

sin2乗とcos2乗を足すと1になる性質を利用しても良いですが，上の式で解くと少なくともsin関数で保証されている精度で解が得られることが確定するのでおすすめです．

### StdArt_Tan
$\tan(x) = \frac{\sin(x)}{\cos(x} $

### StdArt_Asin
$y = \sin(x)$ と $\arcsin(y) = x$ は

必要十分条件を満たしているので，二本木法などを用いることで一位に求めることができます．

f(x)が短調増加であることに変わりはないのですがf'(x)が単調増加ではないのでニュートン法では解が求まらない場合があります．

### StdArt_Acos
$\arccos(x) = \arcsin(\frac{\pi}{2} - x)$

### StdArt_Atan
$\arctan(x) = \arcsin(\frac{1}{(1+x)^{1/2}})$

### StdArt_Atan2
StdArt_Atan(aY / aX);

の aY や aX が第何事象に属するかによって変わる．

### StdArt_Cosh
$\cosh(x) = \frac{\exp(x) + \exp(-x)}{2}$

### StdArt_Log
Expのx軸とy軸を反転させたものより適切な回数の2分木で求まる．
高校数学より，底がeなので注意

### StdArt_Log10
$\log_{10}(x) = \frac{\log_{e}(x)}{\log_{e}(10.0)}$

高校数学より

### StdArt_Pow
$x^{(y)} = e^{y * \log_{e}(x)}$

高校数学より
