#include <string>
#include <vector>

using namespace std;

class Pakage
{
public:
	Pakage(string name, string version,string description);
	int create_control(string path_dir_root);
	int create_dpkg_file(string path_dir_dpkg);
	void add_depends(Pakage pkg);
	string get_version();
	string get_name();
private:
	string name = "";
	string arch = "amd64"; //Architecture
	string version = "0";
	string provides; //записывается исполняймый файл какета не обезателен
	string replaces; //не обезателен записывается пакет который может замещять этот
	string maintainer = "Dmitry Lebedev <D.Lebedev@irbis.su>"; //создатель пакета 
	string section = "misc"; 
	vector<Pakage> depends; //список зависимостей пакета
	string descr = "";
	size_t size = 0; //размер данных в пакете
	 
};
