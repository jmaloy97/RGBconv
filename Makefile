all:
	mkdir -p bin
	g++ -o ./bin/RGBconv-linux main.cpp bitmap.cpp dec_to_hex.cpp hex_to_dec.cpp mainMenu.cpp
	i686-w64-mingw32-g++ -o ./bin/RGBconv-win32.exe main.cpp bitmap.cpp dec_to_hex.cpp hex_to_dec.cpp mainMenu.cpp
	x86_64-w64-mingw32-g++ -o ./bin/RGBconv-amd64.exe main.cpp bitmap.cpp dec_to_hex.cpp hex_to_dec.cpp mainMenu.cpp	

linux:
	mkdir -p bin
	g++ -o ./bin/RGBconv-linux main.cpp bitmap.cpp dec_to_hex.cpp hex_to_dec.cpp mainMenu.cpp

win32:
	mkdir -p bin
	i686-w64-mingw32-g++ -o ./bin/RGBconv-win32.exe main.cpp bitmap.cpp dec_to_hex.cpp hex_to_dec.cpp mainMenu.cpp

amd64:
	mkdir -p bin
	x86_64-w64-mingw32-g++ -o ./bin/RGBconv-amd64.exe main.cpp bitmap.cpp dec_to_hex.cpp hex_to_dec.cpp mainMenu.cpp
