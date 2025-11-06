# MC3DSPluginFramework

Minecraft 3DS 向けのプラグイン開発用フレームワークです。  
一部の機能はゲームスレッド停止時に使用するとフリーズやクラッシュが起きるので注意してください。


## 使い方
`MC3DSPluginFramework.hpp` をインクルードして使用してください。

```cpp
#include "MC3DSPluginFramework.hpp"
using namespace MC3DSPluginFramework;
