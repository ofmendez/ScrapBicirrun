#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


vector<string> split(string line, string delimiter);

int main(int argc, char const *argv[]) {
	fstream fileSource , fileResut;

	fileSource.open("RawData.txt", ios::in);
	fileResut.open("ExcelResult.csv", ios::app | ios::in);

	string line ="";
	int nLine=0;
	
	fileResut.seekg (0, fileResut.end);
	int length = fileResut.tellg();
	if (length == 0) {
		fileResut<< "FECHA,HORA, CALLE 26 , CALLE 45 , CALLE 53 , CYT , RESIDENCIAS UNIVERSITARIAS , URIEL GUTIERREZ\n";
	}
	fileResut.clear();

	vector<string> parts;
	while(getline( fileSource, line) ){
		if (!nLine) {
			fileResut<< line<<"";
		}else{
			line.erase(0,1);
			parts = split(line," ");
			fileResut<<parts[0]<<"";
		}
		nLine =  nLine == 6? 0 : nLine+1;
		fileResut<< (!nLine?  "\n" : " , ");

	}
	return 0;
}

vector<string> split(string line, string delimiter){
    vector<string> x;

    string aux = "";
    for(int i = 0; i < line.size(); i++){
        if(line[i] == delimiter[0] || i == line.size() - 1){
            if(i == line.size() - 1 && line[ line.size() - 1] != delimiter[0])
                aux += line[ line.size() - 1 ];
            x.push_back(aux);
            aux = "";
        }else{
            aux += line[i];
        }
    }

    return x;
}