all:
	mkdir bin
	g++ -o ./bin/RGBconv main.cpp bitmap.cpp dec_to_hex.cpp hex_to_dec.cpp mainMenu.cpp
	i686-w64-mingw32-g++ -o ./bin/RGBconv-win32.exe main.cpp bitmap.cpp dec_to_hex.cpp hex_to_dec.cpp mainMenu.cpp
	x86_64-w64-mingw32-g++ -o ./bin/RGBconv-amd64.exe main.cpp bitmap.cpp dec_to_hex.cpp hex_to_dec.cpp mainMenu.cpp	

linux:
	mkdir bin
	g++ -o ./bin/RGBconv main.cpp bitmap.cpp dec_to_hex.cpp hex_to_dec.cpp mainMenu.cpp

win32:
	mkdir bin
	i686-w64-mingw32-g++ -o ./bin/RGBconv-win32.exe main.cpp bitmap.cpp dec_to_hex.cpp hex_to_dec.cpp mainMenu.cpp

amd64:
	mkdir bin
	x86_64-w64-mingw32-g++ -o ./bin/RGBconv-amd64.exe main.cpp bitmap.cpp dec_to_hex.cpp hex_to_dec.cpp mainMenu.cpp
