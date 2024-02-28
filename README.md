# 自作関数によるc標準関数による実装

# プログラミングをする前に気をつけること

## 環境構築
メールで送られてきた https://jet-blog.com/clang_lesson002/ に従い作業してください．  
たぶん2022年版を推奨されますが，2019でも2022でも変わらないと思います．  
よくある勘違いとして，
- Visual Studio (VS)
- Visual Studio Installer
- Visual Studio Code
のこれらはそれぞれ異なるアプリケーションです．  
まずwebサイトでVisual Studio Installerをダウンロードし，Visual Studio Installerを用いてVisual Studioをインストールします．  
今回の課題をするにあたってVSCは必須ではありません．

これらに注意して一通りインストールできたらエクスプローラとデバッグ出力を表示させておくと便利だと思います．  

<img src="/img/vsstatus.png" alt="vsstatus" width="480" height="270">

またコーディング自体はVScodeを使うともっと楽だと思いますがパソコンに慣れてないならVSで問題ないです．  
上の画像のような状況で |> ローカルwindowsデバッガ― を押して下の画像のようにステータス0で終了していれば正常終了している状況です．  
うまくいかなかったら画面共有とかで教えられるかもです．

<img src="/img/exitw0.png" alt="exitw0" width="480" height="270">
