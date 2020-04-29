## これはなに
M5Stackのボタンでリモート会議アプリZoomの音声や映像のON/OFFを切り替えるものです。MacOS専用です。

## なにがいいの
Zoomのアプリがアクティブでないときも、ボタンを押せば音声や映像のON/OFFを切り替えることができます。

Zoomで会議をしているとき、自身の音声や映像をOFFにして、別の作業をしていることがあります。そのときに会議の参加者から話しかけられると、
「Zoomをフォアグラウンドに持ってくる」「ミュートボタンやビデオの開始ボタンを押す」というように作業が必要になります。焦るとこれがなかなかうまくいきません。
そんなときにこのボタンが有効です。

## どうやって動かすの
#### [zoomctl.py](server/zoomctl.py)
Python3のプログラムです。Python3.7とFlaskフレームワークで動きます。Flaskがインストールされていない場合は、`pip install flask`でインストールしてください。
動かし方は以下のとおりです。ポート番号5000でWebサーバが立ち上がります。セキュリティには一切の配慮がありません。

```bash
> python3 zoomctl.py
```

#### [M5Stack](m5stack)
M5Stackのプログラムがあります。[main.h](m5stack/src/main.h)の`SSID`と`PASSWD`にお使いのWiFiアクセスポイントとそのパスワードを、`SERVER`には[zoomctl.py](server/zoomctl.py)を動かしているPCのIPアドレスやドメイン解決できる名前を入れてください。

PlatformIOなどでコンパイルしてお手持ちのM5Stackにアップロードしてください。

M5Stack上の左のボタンを押すとMuteのON/OFFが、右のボタンを押すとカメラのON/OFFが切り替わります。

## どういう仕組み？
M5Stack -(HTTP GET Request)-> [zoomctl.py](server/zoomctl.py) -(JXA)-> Zoom という流れで制御しています。
zoomctl.pyはos.system()を使ってJXAを実行するコマンドを呼び出しています。JXAでは、(1) Zoom.usという名前のアプリをフォアグラウンドに持ってくる、(2) キーボードショートカットを送る、という処理を実行しています。JXAはAppleScriptのJavascript版だと思ってください。
