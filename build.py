# Helper python program 

import sys
from os import system
if sys.platform == "win32":
	usingVS = input("Do you want to use Visual Studio 2019? Y/N: ")
	if usingVS == "Y" or usingVS == 'y':
		system("premake5 vs2019")
		system("start Hearth.sln")
	else:
		system("premake5 gmake2")
		system("make")
		usingVS = input("Do you want to use Visual Studio Code? Y/N: ")
		if usingVS == 'Y' or usingVS == 'y':
			system("code .")
		system("start bin/Debug/Hearth.exe")

else:
	usingVS = input("Do you want to use Visual Studio Code? Y/N: ")
	if usingVS == 'Y' or usingVS == 'y':
		system("code .")
	system("premake5 gmake")
	system("make")
	system("./bin/Debug/Hearth")
system("exit")
