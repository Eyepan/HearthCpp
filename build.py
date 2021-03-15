import sys
from os import system
if sys.platform == "win32":
	usingVS = input("Do you want to use Visual Studio 2019? Y/N: ")
	if usingVS == "Y":
		system("premake5 vs2019")
		system("start Hearth.sln")
	else:
		system("premake5 gmake2")
		system("mingw32-make")
		system("start bin/Debug/Hearth.exe")

else:
	system("premake5 gmake")
	system("make")
	system("./bin/Debug/Hearth")
exit()