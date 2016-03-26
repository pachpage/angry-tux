**Windows plateform**

The game requires Box2D and SFML librairies. If you download the full version of the game, these dll are included in the archive.

You can also download the lite version and download librairies separately.

Dll are available from here : http://code.google.com/p/angry-tux/downloads/detail?name=windows_dll.zip&can=2&q=#makechanges


**Linux plateform**

If you have some trouble to install Box2D and SFML, you can do this :

```
cd angry-tux/ExternLibrairies/SFML-1.6/lib
sudo cp libsfml-audio.so /usr/lib/libsfml-audio.so.1.6
sudo cp libsfml-graphics.so /usr/lib/libsfml-graphics.so.1.6
sudo cp libsfml-system.so /usr/lib/libsfml-system.so.1.6
sudo cp libsfml-window.so /usr/lib/libsfml-window.so.1.6

cd ../../Box2D_v2.1.2/Box2D/Build/Box2D
sudo cp libBox2D.so /usr/lib/libBox2D.so.2.1.0
```