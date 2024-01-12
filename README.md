# so-long
![so-longpre](https://github.com/yoshiddddd/so_long/assets/83491254/4f2aef83-ee9d-49ee-8d2d-7ba271d23a4c)  

42 challenges
## Overview  
グラフィカルライブラリを使用した2Dゲームです。  
Item(鍵)を全て回収したのち、Goal(宝箱)にたどり着くとクリアです。
## Requiremnt
-macOS  
-MiniLibx 

ゲームをプレイするには[MiniLibx](https://github.com/42Paris/minilibx-linux)というグラフィカルライブラリをインストールする必要があります。

## Usage
`make`すると`so_long`という実行ファイルが作成されます。  

`./so_long maps/map1.var`と、マップ情報を引数に渡してあげてゲームを開始します。  


| key | Action |
|:---:|:---:|
|`W`|Up|
|`S`|Down|
|`A`|Left|
|`D`|Right|

全てのItemを回収しきらないとゲームをクリアすることができません。

## Features
マップは以下の文字によって構成されています。
| char | mean |
|:---:|:---:|
| `1` | Wall |
| `0` | Floor |
| `C` | Item |
| `P` | Player |
| `E` | Goal |

![スクリーンショット 2024-01-12 21 01 46](https://github.com/yoshiddddd/so_long/assets/83491254/8027e16c-5a71-43c7-9d16-77287aae0a81)
→ ![スクリーンショット 2024-01-12 23 11 05](https://github.com/yoshiddddd/so_long/assets/83491254/0ecf9565-093f-4a4a-807c-733718630c57) 

#### ＊mapは以下の条件を満たしていないとゲームを開始することができません。
- マップの外枠が`1`(壁)で囲われていない
- どれか一つでもアイテムが存在しない
- プレイヤーの初期位置からゴールまでが到達不可能

これらはプログラムによって判定され、エラーが返ります。
  
