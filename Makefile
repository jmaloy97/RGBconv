RGBconv:
	g++ -o RGBconv main.cpp bitmap.cpp dec_to_hex.cpp hex_to_dec.cpp mainMenu.cpp

clean:
	rm RGBconv