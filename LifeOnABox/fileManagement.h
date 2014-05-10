#include "topFunctions.h"

struct Changes {
	short BlockType;
	short x;
	short y;
	short z;
};
Changes changesSinceLastSave[100];

std::string ReadTxtFile(std::string Location) {
	std::ifstream File;
	File.open(Location);
	std::string TextToReturn;
	getline(File, TextToReturn);
	File.close();
	return TextToReturn;
}

void WriteTxtFile(std::string Location, std::string Input) {
	std::ofstream File;
	File.open(Location);
	File << Input;
	File.close();
}

int StringCount(std::string Text, std::string WhatToCount) {
	if (Text.length() < WhatToCount.length()) {
		return 0;
	}
	int Count = 0;
	for (int i = 0; i < Text.length() - (WhatToCount.length() - 1); i++) {
		if (Text.substr(i, WhatToCount.length()) == WhatToCount) {
			Count++;
		}
	}
	return Count;
}

std::string* Splitter(std::string Text, std::string StringToSplitAt) {
	int Length = StringCount(Text, StringToSplitAt);
	std::string *NewArray = new std::string[Length + 1];

	int Counter = 0;
	std::string RemaningText = Text;
	while (StringCount(RemaningText, StringToSplitAt) != 0) {
		NewArray[Counter] = RemaningText.substr(0, RemaningText.find(StringToSplitAt));
		RemaningText = RemaningText.substr(RemaningText.find(StringToSplitAt) + StringToSplitAt.length(), RemaningText.length() - 1);
		Counter++;
	}
	NewArray[Counter] = RemaningText;

	std::string* Pointer = NewArray;
	return Pointer;
}

int PartsPerPart = 256;

void saveWorld() {
	std::string Data = "A";
	short CurrentType = 0;
	int TimesInARow = 0;
	int Parts = 0;
	for (int x = 0; x < WorldBounds; x++) {
		int YO = WorldBounds;
		int YD = 0;
		int ZO = WorldBounds;
		int ZD = 0;
		if (x < WorldBounds / 4 || x > WorldBounds / 4 * 3) {
			YD = WorldBounds / 4;
			YO = WorldBounds / 4 * 3;
			ZD = WorldBounds / 4;
			ZO = WorldBounds / 4 * 3;
		}
		for (int y = YD; y < YO; y++) {
			if (y < WorldBounds / 4 || y > WorldBounds / 4 * 3) {
				ZD = WorldBounds / 4;
				ZO = WorldBounds / 4 * 3;
			}
			for (int z = ZD; z < ZO; z++) {
				if (CurrentType == World32[x][y][z].Type) {
					TimesInARow++;
				} else {
					if (CurrentType == 10) {
						Data += std::to_string(TimesInARow) + "XA";
					} else {
						Data += std::to_string(TimesInARow) + "X" + std::to_string(CurrentType) + "";
					}
					CurrentType = World32[x][y][z].Type;
					TimesInARow = 1;
					Parts++;
					if (Parts % PartsPerPart == 0) {
						WriteTxtFile("World" + std::to_string(worldNumber) + "-P-" + std::to_string(Parts / PartsPerPart) + ".JB", Data);
						Data = "A";
					}
				}
			}
		}
	}
	WriteTxtFile("World" + std::to_string(worldNumber) + "-P-" + std::to_string(++Parts / PartsPerPart + 1) + ".JB", Data);
	WriteTxtFile("World" + std::to_string(worldNumber) + "-PC.JB", std::to_string(Parts));
	WriteTxtFile("World" + std::to_string(worldNumber) + "-WS.JB", std::to_string(WorldBounds));
	std::cout << Parts / 256 + 1 << "\n";
}

bool DoesWorldExist() {
	if (ReadTxtFile("World" + std::to_string(worldNumber) + "-PC.JB") != "")
		return true;
	return false;
}

void loadWorld() {
	int MainPart = 1;
	int PartCount = 0;
	int BlockCount = 0;
	std::string DataP = ReadTxtFile("World" + std::to_string(worldNumber) + "-PC.JB");
	int MaksParts = atof(DataP.c_str());
	std::string WorldSizeString = ReadTxtFile("World" + std::to_string(worldNumber) + "-WS.JB");
	WorldBounds = atof(WorldSizeString.c_str());
	std::string Data = ReadTxtFile("World" + std::to_string(worldNumber) + "-P-" + std::to_string(MainPart) + ".JB");
	std::string *DataParts = Splitter(Data, "X");
	//int Parts = StringCount(Data, "X");
	int PartWeAreAt = -1;
	short CurrentType = 0;
	int TimesBackInARow = 0;
	for (int x = 0; x < WorldBounds; x++) {
		int YO = WorldBounds;
		int YD = 0;
		int ZO = WorldBounds;
		int ZD = 0;
		if (x < WorldBounds / 4 || x > WorldBounds / 4 * 3) {
			YD = WorldBounds / 4;
			YO = WorldBounds / 4 * 3;
			ZD = WorldBounds / 4;
			ZO = WorldBounds / 4 * 3;
		}
		for (int y = YD; y < YO; y++) {
			if (y < WorldBounds / 4 || y > WorldBounds / 4 * 3) {
				ZD = WorldBounds / 4;
				ZO = WorldBounds / 4 * 3;
			}
			for (int z = ZD; z < ZO; z++) {
				if (TimesBackInARow == 0) {
					PartCount++;
					if (MaksParts == PartCount) {
						UpdateWorldBlocksForAirLook(WorldBounds);
						UpdateMiniMapView(false, 0, 0);
						Position = vector3D(-WorldBounds / 4, -WorldBounds / 4, -WorldBounds / 4);
						ResetTime();
						ProgramInit();
						gamestate = 1;
						return;
					}
					PartWeAreAt++;
					if (PartWeAreAt == PartsPerPart) {
						PartWeAreAt = 0;
						MainPart++;
						Data = ReadTxtFile("World" + std::to_string(worldNumber) + "-P-" + std::to_string(MainPart) + ".JB");
						DataParts = Splitter(Data, "X");
						std::cout << (float)BlockCount / (WorldBounds * WorldBounds * WorldBounds / 3.5) * 100 << " %  \t\t\t" << BlockCount << " blocks out of " << (int)(WorldBounds * WorldBounds * WorldBounds / 3) << " blocks\n";
					}
					std::string NextType = DataParts[PartWeAreAt + 1].substr(0, 1);
					if (NextType == "A") {
						CurrentType = 10;
					} else {
						CurrentType = atof(NextType.c_str());
					}
					TimesBackInARow = atof(DataParts[PartWeAreAt].substr(1, DataParts[PartWeAreAt].length() - 1).c_str());
				}
				World32[x][y][z].Type = CurrentType;
				BlockCount++;
				TimesBackInARow--;
				//std::cout << TimesBackInARow << "\n";
			}
		}
	}
	UpdateWorldBlocksForAirLook(WorldBounds);
	UpdateMiniMapView(false, 0, 0);
	Position = vector3D(-WorldBounds / 4, -WorldBounds / 4, -WorldBounds / 4);
	ResetTime();
	ProgramInit();
	gamestate = 1;
}